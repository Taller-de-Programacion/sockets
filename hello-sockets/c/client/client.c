#define _POSIX_C_SOURCE 201112L // Habilita getaddrinfo
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include "client.h"

static const char msg[] = "Hello server";

#define RECV_BUFFER_SIZE 16
#define MSG_SIZE 12

int client_create(struct client_t* self) {
    self->fd = -1;
    return 0;
}

int client_destroy(struct client_t* self) {
    self->fd = -1;
    return 0;
}

int client_run(struct client_t* self, const char* host, const char* service) {
    /**
     * Intento conectarme al servidor
     **/
    if (client_connect(self, host, service)) {
        printf("No se pudo conectar al servidor");
        return 1;
    }

    /**
     * Envío mensaje al servidor
     */
    client_send_hello(self);
    
    /**
     * Envío recibo respuesta del servidor
     */
    client_recv_hello(self);
    
    /**
     * Libero recursos 
     */
    client_close(self);
    return 0;
}

int client_connect(struct client_t* self, const char* host, const char* service) {
    struct addrinfo hints, *serv_info;
    memset(&hints, 0, sizeof(struct addrinfo));
    printf("Conectandose a %s (%s)\n", host, service);

    // serv_info es una lista enlazada, igualmente me quedo con la primer opción
    int error = getaddrinfo(host, service, &hints, &serv_info);
    if (error) {
        printf("connect: getaddrinfo error: %s\n", gai_strerror(error));
        return -1;
    }
    self->fd = socket(serv_info->ai_family, serv_info->ai_socktype, serv_info->ai_protocol);
    connect(self->fd, serv_info->ai_addr, serv_info->ai_addrlen);

    // libero recursos de getaddrinfo
    freeaddrinfo(serv_info);
    printf("File descriptor creado: %d\n", self->fd);
    return self->fd == -1;
}

int client_close(struct client_t* self) {
    shutdown(self->fd, 2);
    close(self->fd);
    return 0;
}

int client_send_hello(struct client_t* self) {
    /**
     * MSG_NOSIGNAL para evitar que salte una señal en caso
     * de que el socket se haya cerrado
     */
    printf("Enviando %s\n", msg);
    int bytes = send(self->fd, msg, sizeof(msg) - 1, MSG_NOSIGNAL);
    printf("Enviado %d bytes\n", bytes);
    return 0;
}

int client_recv_hello(struct client_t* self) {
    char buf[RECV_BUFFER_SIZE];
    // Voy a recibir "Hello server", 12 caracteres
    int bytes = recv(self->fd, buf, MSG_SIZE, 0);
    buf[MSG_SIZE] = 0;
    printf("Recibido %d bytes: %s\n", bytes, buf);
    return 0;
}
