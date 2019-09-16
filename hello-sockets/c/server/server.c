#define _POSIX_C_SOURCE 201112L // Habilita getaddrinfo
#include <unistd.h>
#include <arpa/inet.h> // inet_ntop
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include "server.h"

#define ACCEPT_QUEUE_LEN 10

int server_create(struct server_t* self) {
    self->fd = -1;
    return 0;
}

int server_destroy(struct server_t* self) {
    self->fd = -1;
    return 0;
}

int server_run(struct server_t* self, char* service) {
    if (server_bind_listen(self, service)) {
        printf("No se pudo tomar el puerto");
        return 1;
    }
    
    /**
     * Me quedo esperando una conexión entrante
     */
    struct client_t client;
    if (server_accept(self, &client)) {
        printf("No se pudo aceptar el cliente");
        return 1;
    }
    
    /**
     * Recibo un mensaje del cliente
     */
    client_recv_hello(&client);

    /**
     * Envío un mensaje al cliente
     */
    client_send_hello(&client);

    /**
     * Libero recursos 
     */
    client_close(&client);
    server_close(self);
    return 0;
}

int server_bind_listen(struct server_t* self, char* port) {
    int fd = -1;
    // Hints son las opciones que configuro, server info posee los datos
    // devueltos por el sistema.
    struct addrinfo hints, *server_info;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    getaddrinfo(NULL, port, &hints, &server_info);

    fd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    
    // Así se puede reutilizar el puerto sin esperar timeout
    int val = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    
    bind(fd, server_info->ai_addr, server_info->ai_addrlen);

    freeaddrinfo(server_info);
    listen(fd, ACCEPT_QUEUE_LEN);
            
    self->fd = fd;
    return 0;
}

int server_accept(struct server_t* self, struct client_t* client) {
    char addressBuf[INET_ADDRSTRLEN];
    struct sockaddr_in address;
    socklen_t addressLength = (socklen_t) sizeof(address);

    int newSocket = accept(self->fd, (struct sockaddr *)&address,
                           &addressLength);
    inet_ntop(AF_INET, &(address.sin_addr), addressBuf, INET_ADDRSTRLEN);
    printf("Se conectó un usuario: %s\n", addressBuf);
    // Está rompiendo su encapsulamiento, coxhino!
    client->fd = newSocket;
    return 0;
}

int server_close(struct server_t* self) {
    shutdown(self->fd, 2);
    close(self->fd);
    return 0;
}
