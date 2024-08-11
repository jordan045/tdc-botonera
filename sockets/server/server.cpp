#include <iostream>
#include <cstring>
#include <thread>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

class Servidor {
public:
    Servidor(int puerto);
    ~Servidor();
    void iniciar();
    std::string recibir();
    void enviar(const std::string& mensaje);
    int cliente_fd;

private:
    int server_fd;
    struct sockaddr_in address;
    int addrlen;
    char buffer[BUFFER_SIZE];

    void crearSocket();
    void configurarSocket();
    void enlazarSocket();
    void escucharConexiones();
    void aceptarConexion();
};

Servidor::Servidor(int puerto) : server_fd(0), cliente_fd(0), addrlen(sizeof(address)) {
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(puerto);
    std::memset(buffer, 0, BUFFER_SIZE);
}

Servidor::~Servidor() {
    if (cliente_fd > 0) {
        close(cliente_fd);
    }
    if (server_fd > 0) {
        close(server_fd);
    }
}

void Servidor::iniciar() {
    crearSocket();
    configurarSocket();
    enlazarSocket();
    escucharConexiones();
    aceptarConexion();
}

void Servidor::crearSocket() {
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Fallo al crear el socket");
        exit(EXIT_FAILURE);
    }
}

void Servidor::configurarSocket() {
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        /*
        SO_REUSEADDR y SO_REUSEPORT permiten reutilizar la dirección y el puerto.
        (SOL_SOCKET indica la opcion a modificar).
        */
        perror("Fallo en setsockopt");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
}

void Servidor::enlazarSocket() {
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Fallo en bind");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
}

void Servidor::escucharConexiones() {
    if (listen(server_fd, 3) < 0) {
        perror("Fallo en listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    // listen queda esperando una conexion, frena la ejecucion del programa
    std::cout << "Servidor escuchando en el puerto " << ntohs(address.sin_port) << std::endl;
}

void Servidor::aceptarConexion() {
    if ((cliente_fd = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Fallo en accept");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
}

std::string Servidor::recibir() {
    int msglen = read(cliente_fd, buffer, BUFFER_SIZE);
    if (msglen < 0) {
        return "\0";
    }
    return std::string(buffer);
}

void Servidor::enviar(const std::string& mensaje) {
    send(cliente_fd, mensaje.c_str(), mensaje.size(), 0);
    std::cout << "Mensaje de respuesta enviado: " << mensaje << std::endl;
}


void callback_mensajes_recibidos(Servidor *servidor) {
    std::string buffer;

    while (1) {

        buffer = servidor->recibir();
        if (buffer.size() > 0) {
            std::cout << "Mensaje recibido: " << buffer << std::endl;
            buffer.clear();

            servidor->enviar("Genial");
        }

    }
}

int main() {
    Servidor servidor(PORT);
    servidor.iniciar();

    std::thread hilo_recibidos(callback_mensajes_recibidos, &servidor);
    hilo_recibidos.detach();

    while (1);
    return 0;
}
