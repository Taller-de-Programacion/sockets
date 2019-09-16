#!/usr/bin/env python3
import socket
import sys

RECV_SIZE = 12

"""Espera un saludo del cliente y envía un mensaje 'hello client' al cliente"""
class Server(object):
    def __init__(self, port):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        address = ('0.0.0.0', int(port))
        self.sock.bind(address)
        self.sock.listen()

    def accept_client(self):
        connection = self.sock.accept()
        return Client(connection)

class Client(object):
    def __init__(self, connection):
        self.sock = connection[0]
        print("Cliente nuevo desde {}.".format(connection[1]))

    def send_hello(self):
        sent = self.sock.send("hello server".encode('utf-8'))
        print("Enviado {} bytes".format(sent))

    def recv_hello(self):
        msg = self.sock.recv(RECV_SIZE)
        print("Recibido: {}".format(msg))


def main():
    if len(sys.argv) < 2:
        print("Uso: ./server.py <puerto>")
        return 1
    server = Server(sys.argv[1])
    client = server.accept_client()
    client.recv_hello()
    client.send_hello()

if __name__ == '__main__':
    main()