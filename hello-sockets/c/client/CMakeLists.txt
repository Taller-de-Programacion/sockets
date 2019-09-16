cmake_minimum_required(VERSION 2.8)

project(hello-sockets)

set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic -Wno-unused-parameter -std=c99")

add_executable(client
    main.c
    client.c
)
