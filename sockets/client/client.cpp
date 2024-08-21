#include <iostream>
#include <cstring>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <functional>
#include <atomic>
// Clase Cliente
#include <chrono>
// Ejemplo en main

#define PORT 8080
#define BUFFER_SIZE 1024
#define NAMESPACE_SIZE 20

struct MensajeSerializado {
    char namespace_[NAMESPACE_SIZE];
    char mensaje[BUFFER_SIZE];
    uint32_t longitud;
};

class Cliente
{
public:
    Cliente(const std::string &direccionIP, int puerto);
    ~Cliente();
    void conectar(std::function<void(const std::string&, const std::string&)> callback);
    int enviar(const char namespace_[NAMESPACE_SIZE], const char mensaje[BUFFER_SIZE]);
    int recibir(char mensaje[1024], char namespace_[20]);
    void esperar_mensajes(std::function<void(const std::string&, const std::string&)> callback);

private:
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    std::thread worker_thread;
    std::atomic<bool> stop_thread;

    void crearSocket();
    void configurarDireccion(const std::string &direccionIP, int puerto);
    void stop();
};

Cliente::Cliente(const std::string &direccionIP, int puerto) : sock(0)
{
    std::memset(buffer, 0, BUFFER_SIZE);
    configurarDireccion(direccionIP, puerto);
}

Cliente::~Cliente()
{
    if (sock > 0)
    {
        close(sock);
    }
    stop();
}


void Cliente::stop()
{
    stop_thread = true;
    if (worker_thread.joinable()) {
        worker_thread.join();
    }
}

void Cliente::crearSocket()
{
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "Error al crear el socket" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Cliente::configurarDireccion(const std::string &direccionIP, int puerto)
{
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(puerto);

    if (inet_pton(AF_INET, direccionIP.c_str(), &serv_addr.sin_addr) <= 0)
    {
        std::cerr << "Dirección inválida / Dirección no soportada" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Cliente::conectar(std::function<void(const std::string&, const std::string&)> callback)
{
    crearSocket();
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        std::cerr << "Fallo en la conexión" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        // Conexion exitosa
        std::cout << "Conectado al servidor en puerto " << PORT << std::endl;

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
}

int Cliente::enviar(const char namespace_[NAMESPACE_SIZE], const char mensaje[BUFFER_SIZE])
{
    MensajeSerializado mensaje_formateado;
    strcpy(mensaje_formateado.mensaje, mensaje);
    strcpy(mensaje_formateado.namespace_, namespace_);
    // Copia cadena sobre la estructura

    size_t bytes_sent = send(sock, &mensaje_formateado, sizeof(mensaje_formateado), 0);

    return bytes_sent;
}

int Cliente::recibir(char mensaje[1024], char namespace_[20])
{
    MensajeSerializado mensajeRecibido;
    size_t bytes_received = recv(sock, &mensajeRecibido, sizeof(MensajeSerializado), 0);

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

    Cliente cliente("127.0.0.1", PORT);
    cliente.conectar(callback);

    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
    // Es necesario un pequeño retardo antes de enviar el primer mensaje

    cliente.enviar("namespace1", "Hola, servidor en namespace1!");
    cliente.enviar("namespace2", "Hola, servidor en namespace2!");

    while (true);

    return 0;
}
