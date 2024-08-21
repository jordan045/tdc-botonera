#include <iostream>
#include <cstring>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <functional>
#include <atomic> // Para matar el hilo secundario
// Clase Servidor

#define PORT 8080
#define BUFFER_SIZE 1024

struct MensajeSerializado {
    char namespace_[20];
    char mensaje[BUFFER_SIZE];
    uint32_t longitud;
};

class Servidor
{
public:
    Servidor(int puerto);
    ~Servidor();
    void iniciar(std::function<void(const std::string&, const std::string&)> callback);
    int enviar(const char namespace_[20], const char mensaje[BUFFER_SIZE]);
    int recibir(char mensaje[1024], char namespace_[20]);

private:
    int server_fd;
    int cliente_fd;
    struct sockaddr_in address;
    int addrlen;
    char buffer[BUFFER_SIZE];
    std::thread worker_thread;
    std::atomic<bool> stop_thread;

    void crearSocket();
    void configurarSocket();
    void enlazarSocket();
    void escucharConexiones();
    void aceptarConexion();
};

Servidor::Servidor(int puerto) : server_fd(0), cliente_fd(0), addrlen(sizeof(address))
{
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(puerto);
    std::memset(buffer, 0, BUFFER_SIZE);
}

Servidor::~Servidor()
{
    if (cliente_fd > 0)
    {
        close(cliente_fd);
    }
    if (server_fd > 0)
    {
        close(server_fd);
    }
}

void Servidor::iniciar(std::function<void(const std::string&, const std::string&)> callback)
{
    crearSocket();
    configurarSocket();
    enlazarSocket();
    escucharConexiones();
    aceptarConexion();

    stop_thread = false;
    worker_thread = std::thread([this, callback]() {
        char mensaje[1024], namespace_[20];

        while (!stop_thread)
        {
            if (recibir(mensaje, namespace_)) {
                callback(mensaje, namespace_);
            }
        }
    });
}

void Servidor::crearSocket()
{
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Fallo al crear el socket");
        exit(EXIT_FAILURE);
    }
}

void Servidor::configurarSocket()
{
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Fallo en setsockopt");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
}

void Servidor::enlazarSocket()
{
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Fallo en bind");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
}

void Servidor::escucharConexiones()
{
    if (listen(server_fd, 3) < 0)
    {
        perror("Fallo en listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    std::cout << "Servidor escuchando en el puerto " << ntohs(address.sin_port) << std::endl;
}

void Servidor::aceptarConexion()
{
    if ((cliente_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("Fallo en accept");
        close(server_fd);
        exit(EXIT_FAILURE);
    } else {
        std::cout << "Conexion aceptada" << std::endl;
    }
}

int Servidor::enviar(const char namespace_[20], const char mensaje[BUFFER_SIZE])
{
    MensajeSerializado mensaje_formateado;
    strcpy(mensaje_formateado.mensaje, mensaje);
    strcpy(mensaje_formateado.namespace_, namespace_);

    size_t bytes_sent = send(cliente_fd, &mensaje_formateado, sizeof(MensajeSerializado), 0);

    return bytes_sent;
}

int Servidor::recibir(char mensaje[1024], char namespace_[20])
{
    MensajeSerializado mensajeRecibido;
    size_t bytes_received = recv(cliente_fd, &mensajeRecibido, sizeof(MensajeSerializado), 0);

    strcpy(mensaje, mensajeRecibido.mensaje);
    strcpy(namespace_, mensajeRecibido.namespace_);

    return mensajeRecibido.longitud;
}

int main()
{
    auto callback = [](const std::string& message, const std::string& namespace_) {
        std::cout << message << " : " << namespace_ << std::endl;
    };
    // auto para que el compilador deduzca el tipo

    Servidor servidor(PORT);
    servidor.iniciar(callback);

    while (true);

    return 0;
}