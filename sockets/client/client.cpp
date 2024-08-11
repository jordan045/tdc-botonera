#include <iostream>
#include <cstring>
#include <thread>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

class Cliente
{
public:
    Cliente(const std::string &direccionIP, int puerto);
    ~Cliente();
    void conectar();
    void enviar(const std::string &mensaje);
    std::string recibir();
    void esperar_mensajes();

private:
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    void crearSocket();
    void configurarDireccion(const std::string &direccionIP, int puerto);
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

void Cliente::enviar(const std::string &mensaje)
{
    send(sock, mensaje.c_str(), mensaje.size(), 0);
    std::cout << "Mensaje enviado: " << mensaje << std::endl;
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

void Cliente::esperar_mensajes() {
    std::string buffer;

    while (true) {
        buffer = recibir();
        if (!buffer.empty()) {
            std::cout << "Mensaje recibido: " << buffer << std::endl;
            buffer.clear();
        }
    }
}

int main()
{
    Cliente cliente("127.0.0.1", PORT);
    cliente.conectar();

    std::thread hilo_recibidos(&Cliente::esperar_mensajes, &cliente);
    hilo_recibidos.detach();

    for (int i = 0; i < 5; i++)
    {
        cliente.enviar("Hola, servidor!");
    }

    while (true);

    return 0;
}
