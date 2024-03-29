#include <stdio.h>
#include "server.h"
#include "client.h"

#define ARGS_PORT 1

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Uso: ./server <puerto>");
    return 1;
    }
    struct server_t server;
    /**
     * Inicializo el socket servidor y reservo un puerto para escuchar
     * conexiones entrantes
     */
    server_create(&server);

    char* service = argv[ARGS_PORT];
    server_run(&server, service); 
    server_destroy(&server);
}
