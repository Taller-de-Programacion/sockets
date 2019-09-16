cmake_minimum_required(VERSION 2.8)

project(hello-sockets)

set(CMAKE_C_FLAGS "-ggdb -Wall -Wextra -pedantic -Wno-unused-parameter -std=c99")

add_executable(server
    main.c
    client.c
    server.c
)

