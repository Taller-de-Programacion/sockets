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
 * Se conecta a un servidor con la dirección dada por <host> y <service>
 * Envía  un mensaje "hello server" al servidor y luego espera su respuesta.
 */
int client_run(struct client_t* self, const char* host, const char* service);

/**
 * Envía el mensaje "Hello client"
 */
int client_connect(struct client_t* self, const char* host, const char* service);

/**
 * Envía el mensaje "Hello client"
 */
int client_recv_hello(struct client_t* self);

/**
 * Envía el mensaje "Hello server"
 */
int client_send_hello(struct client_t* self);

/**
 * Cierra los canales del socket
 */
int client_close(struct client_t* self);

#endif // CLIENT_H
