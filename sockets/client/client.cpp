#include <iostream>
#include <cstring>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
// Clase Cliente
#include <chrono>
// Ejemplo en main

#define PORT 8080
#define BUFFER_SIZE 1024

struct MensajeSerializado {
    char namespace_[20];
    char mensaje[BUFFER_SIZE];
    uint32_t longitud;
};

class Cliente
{
public:
    Cliente(const std::string &direccionIP, int puerto);
    ~Cliente();
    void conectar();
    int enviar(const char namespace_[20], const char mensaje[BUFFER_SIZE]);
    std::string recibir();
    void esperar_mensajes();

private:
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    void crearSocket();
    void configurarDireccion(const std::string &direccionIP, int puerto);
    void procesarMensaje(const std::string &mensaje);
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

void Cliente::conectar()
{
    crearSocket();
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        std::cerr << "Fallo en la conexión" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Conectado al servidor" << std::endl;
}

int Cliente::enviar(const char namespace_[20], const char mensaje[BUFFER_SIZE])
{
    MensajeSerializado mensaje_formateado;
    strcpy(mensaje_formateado.mensaje, mensaje);
    strcpy(mensaje_formateado.namespace_, namespace_);
    // Copia cadena sobre la estructura

    size_t bytes_sent = send(sock, &mensaje_formateado, sizeof(mensaje_formateado), 0);

    return bytes_sent;
}

std::string Cliente::recibir()
{
    int msglen = read(sock, buffer, BUFFER_SIZE);
    if (msglen < 0)
    {
        return "\0";
    }
    return std::string(buffer);
}

void Cliente::procesarMensaje(const std::string &mensaje)
{
    std::cout << "Mensaje recibido: " << mensaje << std::endl;
}

void Cliente::esperar_mensajes()
{
    std::string mensaje;

    while (true)
    {
        mensaje = recibir();
        if (!mensaje.empty())
        {
            procesarMensaje(mensaje);
        }
    }
}

int main()
{
    Cliente cliente("127.0.0.1", PORT);
    cliente.conectar();

    std::thread hilo_recibidos(&Cliente::esperar_mensajes, &cliente);
    hilo_recibidos.detach();

    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));

    cliente.enviar("namespace1", "Hola, servidor en namespace1!");
    cliente.enviar("namespace2", "Hola, servidor en namespace2!");

    while (true);

    return 0;
}
