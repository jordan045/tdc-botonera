#include <iostream>
#include <cstring>
#include <thread>
#include <map>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

class Servidor
{
public:
    Servidor(int puerto);
    ~Servidor();
    void iniciar();
    void enviar(const std::string &namespace_, const std::string &mensaje);
    std::string recibir();
    void manejarClientes();

private:
    int server_fd;
    int cliente_fd;
    struct sockaddr_in address;
    int addrlen;
    char buffer[BUFFER_SIZE];
    std::map<std::string, std::string> namespaces;

    void crearSocket();
    void configurarSocket();
    void enlazarSocket();
    void escucharConexiones();
    void aceptarConexion();
    std::string extraerNamespace(const std::string &mensaje);
    std::string extraerMensaje(const std::string &mensaje);
    void procesarMensaje(const std::string &mensaje);
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

void Servidor::iniciar()
{
    crearSocket();
    configurarSocket();
    enlazarSocket();
    escucharConexiones();
    aceptarConexion();
    manejarClientes();
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
    }
}

std::string Servidor::recibir()
{
    int msglen = read(cliente_fd, buffer, BUFFER_SIZE);
    if (msglen < 0)
    {
        return "\0";
    }
    return std::string(buffer);
}

void Servidor::enviar(const std::string &namespace_, const std::string &mensaje)
{
    std::string mensaje_formateado = namespace_ + ":" + mensaje;
    send(cliente_fd, mensaje_formateado.c_str(), mensaje_formateado.size(), 0);
}

std::string Servidor::extraerNamespace(const std::string &mensaje)
{
    size_t pos = mensaje.find(':');
    if (pos != std::string::npos)
    {
        return mensaje.substr(0, pos);
    }
    return "";
}

std::string Servidor::extraerMensaje(const std::string &mensaje)
{
    size_t pos = mensaje.find(':');
    if (pos != std::string::npos)
    {
        return mensaje.substr(pos + 1);
    }
    return mensaje;
}

void Servidor::procesarMensaje(const std::string &mensaje)
{
    std::string namespace_ = extraerNamespace(mensaje);
    std::string contenido = extraerMensaje(mensaje);

    // Aquí podrías manejar diferentes namespaces de manera diferente
    enviar(namespace_, "Mensaje recibido en " + namespace_);
}

void Servidor::manejarClientes()
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
    Servidor servidor(PORT);
    servidor.iniciar();

    while (true);

    return 0;
}
