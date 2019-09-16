#include <stdio.h>
#include "client.h"

#define ARGS_HOST 1
#define ARGS_PORT 2

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Uso: ./client <host> <puerto>");
    return 1;
    }
    struct client_t client;
    /**
     * Inicializo el socket cliente 
     */
    const char* host = argv[ARGS_HOST];
    const char* service = argv[ARGS_PORT];
    client_create(&client);
    client_run(&client, host, service);    
    client_destroy(&client);
}
