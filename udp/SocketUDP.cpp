#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

class SocketUDP {
public:
    SocketUDP();
    ~SocketUDP();
    void conectar(const char* ip, int puerto);
    void enviar(const char* mensaje);
    void recibir(char* buffer, size_t tam_buffer);

private:
    int sockfd; 
    struct sockaddr_in direccion_servidor;
};

SocketUDP::SocketUDP() : sockfd(-1) {
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error al crear el socket");
        exit(EXIT_FAILURE);
    }
}

SocketUDP::~SocketUDP() {
    if (sockfd != -1) {
        if (close(sockfd) < 0) {
            perror("Error al cerrar el socket");
        }
    }
}

void SocketUDP::conectar(const char* ip, int puerto) {
    memset(&direccion_servidor, 0, sizeof(direccion_servidor));
    direccion_servidor.sin_family = AF_INET;
    direccion_servidor.sin_port = htons(puerto);
    if (inet_pton(AF_INET, ip, &direccion_servidor.sin_addr) <= 0) {
        perror("Error al convertir la dirección IP");
        exit(EXIT_FAILURE);
    }
}

void SocketUDP::enviar(const char* mensaje) {
    ssize_t enviado = sendto(sockfd, mensaje, strlen(mensaje), 0,
                                (struct sockaddr*)&direccion_servidor, sizeof(direccion_servidor));
    if (enviado < 0) {
        perror("Error al enviar el mensaje");
        exit(EXIT_FAILURE);
    }
}

void SocketUDP::recibir(char* buffer, size_t tam_buffer) {
    socklen_t len = sizeof(direccion_servidor);
    ssize_t recibido = recvfrom(sockfd, buffer, tam_buffer - 1, 0,
                                (struct sockaddr*)&direccion_servidor, &len);
    if (recibido < 0) {
        perror("Error al recibir el mensaje");
        exit(EXIT_FAILURE);
    }

    buffer[recibido] = '\0';
}

int main() {
    SocketUDP cliente;
    cliente.conectar("127.0.0.1", 8080);

    const char* mensaje = "hola";
    cliente.enviar(mensaje);

    char buffer[1024];
    cliente.recibir(buffer, sizeof(buffer));
    std::cout << "Respuesta del servidor: " << buffer << std::endl;

    return 0;
}
