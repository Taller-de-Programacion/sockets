#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include "client.h"

#define RECV_BUFFER_SIZE 16
#define MSG_SIZE 12

static const char msg[] = "Hello client";

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

int client_close(struct client_t* self) {
    shutdown(self->fd, 2);
    close(self->fd);
    return 0;
}
