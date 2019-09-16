#ifndef CLIENT_H
#define CLIENT_H

struct client_t {
    int fd;
};

/**
 * Constructor
 */
int client_create(struct client_t* self);

/**
 * Destructor
 */
int client_destroy(struct client_t* self);

/**
 * Recibe el mensaje "Hello server"
 */
int client_recv_hello(struct client_t* self);

/**
 * Envía el mensaje "Hello client"
 */
int client_send_hello(struct client_t* self);

/**
 * Cierra los canales del socket
 */
int client_close(struct client_t* self);

#endif // CLIENT_H
