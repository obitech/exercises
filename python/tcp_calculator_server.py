#!/usr/bin/python3
"""
tcp_calculator_server.py - A simple TCP server which allows arithmetic calculations. 

Start server with ./python3 tcp_calculator_server [port]
Connect with ./python3 tcp_calculator_client.py [port]
"""

import socket
import sys

class Server:
    client_motd = """
------------------------------------------------------------------------ 
  ________________     ______      __           __      __
 /_  __/ ____/ __ \   / ____/___ _/ /______  __/ /___ _/ /_____  _____
  / / / /   / /_/ /  / /   / __ `/ / ___/ / / / / __ `/ __/ __ \/ ___/
 / / / /___/ ____/  / /___/ /_/ / / /__/ /_/ / / /_/ / /_/ /_/ / /
/_/  \____/_/       \____/\__,_/_/\___/\__,_/_/\__,_/\__/\____/_/

------------------------------------------------------------------------ 
Use:        operator*op1*op2 | exit
Operators:  ADD, SUB, MUL, DIV
Op1, op2:   Integers
Example:    ADD*2*3
            mul*6*6
------------------------------------------------------------------------ 
    """

    client_bye = """
 __________
< Bye Bye! >
 ----------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\   
                ||----w |
                ||     ||
    """

    def __init__(self, port=8080):
        self.port = int(port)

    def run(self):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.bind(("", self.port))
            s.listen(1)
            print(f"Listening on port {self.port}...")

            conn, addr = s.accept()
            with conn:
                print(f"Connection established with {addr[0]}:{addr[1]}")

                conn.send(str.encode(self.client_motd))
                print("MOTD sent")
                while True:
                    data = conn.recv(1024).decode()
                    print(f"Received: {data}")

                    if not data or data == "exit":
                        conn.send(str.encode(self.client_bye))
                        print("ByeBye sent")
                        break

                    result = self.calculate(data)
                    conn.send(str.encode(result))
                    print(f"Sent: {result}")

            print("Connection closed")

        print("Socket closed")

    def calculate(self, args):
        error = [">> Unknown operation!", 
                 ">> Integers required!",
                 ">> Unknown format!"]
        
        operation = ["ADD", "MUL", "DIV", "SUB"]

        # Check for right input format
        try:
            inp = args.split("*")
            if len(inp) != 3:
                raise Exception
        except:
            return error[2]

        # Check for supported operation
        op = inp[0].upper()
        if op not in operation:
            return error[0]

        # Check if operands are integer
        try:
            inp = [int(x) for x in inp[1:]]
        except:
            return error[1]

        # All good
        if op == "ADD":
            result = str(inp[0] + inp[1])
        elif op == "SUB":
            result = str(inp[0] - inp[1])
        elif op == "DIV":
            result = str(inp[0] / inp[1])
        else:
            result = str(inp[0] * inp[1])

        return ">> RESULT*" + result


if __name__ == "__main__":
    if len(sys.argv) == 2:
        try:
            server = Server(int(sys.argv[1]))
        except:
            print("Start server with ./python3 tcp_calculator_server.py [port]")
            sys.exit(-1)
    else:
        server = Server()

    server.run()