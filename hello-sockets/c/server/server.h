#ifndef SERVER_H
#define SERVER_H
#include "client.h"

struct server_t {
    int fd;
};

/**
 * Constructor
 */
int server_create(struct server_t* self);

/**
 * Destructor
 */
int server_destroy(struct server_t* self);

/**
 * Inicia el servidor en el puerto `service`, escucha un
 * *hola mundo* del cliente y luego le responde hola mundo también.
 **/
int server_run(struct server_t* self, char* service);

/**
 * Toma un puerto e inicializa cola de escucha
 */
int server_bind_listen(struct server_t* self, char* service);

/**
 * Se bloquea hasta que un cliente se conecte
 */
int server_accept(struct server_t* self, struct client_t* client);

/**
 * Cierra los canales del socket
 */
int server_close(struct server_t* self);

#endif // SERVER_H
