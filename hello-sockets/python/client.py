#!/usr/bin/env python3
import socket
import sys

RECV_SIZE = 12

"""Envía un mensaje 'hello server' al servidor y espera una respuesta"""
class Client(object):
    def __init__(self, host, port):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        address = (host, port)
        self.sock.connect(address)

    def send_hello(self):
        sent = self.sock.send("hello server".encode('utf-8'))
        print("Enviado {} bytes".format(sent))

    def recv_hello(self):
        msg = self.sock.recv(RECV_SIZE)
        print("Recibido: {}".format(msg))


def main():
    if len(sys.argv) < 3:
        print("Uso: ./client.py <host> <puerto>")
        return 1
    client = Client(sys.argv[1], int(sys.argv[2]))
    client.send_hello()
    client.recv_hello()

if __name__ == '__main__':
    main()