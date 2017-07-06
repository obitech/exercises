#!/usr/bin/python3
"""
tcp_calculator_client.py - Use TCP to connect to a server which allows basic arithmetic calculations. 

Start server with ./python3 tcp_calculator_server [port]
Connect with ./python3 tcp_calculator_client.py [port]
"""

import socket
import sys

class Client:
    def __init__(self, port=8080):
        try:
            self.host = "127.0.0.1"
            self.port = int(port)
        except:
            print("Create instance with Client(host, port)")

    def connect(self):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            try:
                s.connect((self.host, self.port))
            except ConnectionRefusedError:
                print(f"Connection to {self.host}:{self.port} refused. Try different port.")

            while True:
                data = s.recv(1024).decode()

                if not data:
                    break

                print(data)
                inp = input("> ")
                s.send(str.encode(inp))

if __name__ == "__main__":
    if len(sys.argv) == 2:
        try:
            client = Client(int(sys.argv[1]))
        except:
            print("Connect with ./python3 tcp_calculator_client.py [port]")
            sys.exit(-1)
    else:
        client = Client()

    client.connect()