#!/usr/sbin/python3
# switch.py - simulating a basic switching engine

import sys

class Switch:
    # sat[address] = port
    sat = {}
    n = 0

    def __init__(self, n):
        self.n = n;
        print(f"Switch started with {self.n} ports. Enter 'a' to print SAT or 'exit' to quit.")
        print(f"Enter: [port: 1..{self.n}] [src: 1..255] [dest: 1..255]")

    def print(self):
        sat = self.sat
        out = {port: [] for port in range(1, self.n + 1)}

        for k, v in sat.items():
            out[v].append(k)

        print("switch>")
        for k, v in out.items():
            print(f"{k}: ", end = "")
            for x in v:
                print(f"{x} ", end = "")
            print()

    def get_input(self):
        while True:
            inp = input("switch< ")

            if inp == 'a' or inp == 'exit':
                return inp;

            try:
                vals = [int(x) for x in inp.split(" ")]
            except:
                pass

            try:
                if 1 <= vals[0] <= n and 1 <= vals[1] <= 255 and 1 <= vals[2] <= 255:
                    return tuple(vals);
            except:
                pass

            print(f"Enter: [port: 1..{self.n}] [src: 1..255] [dest: 1..255]")

    def run(self, vals):
        port, src, dest = vals
        sat = self.sat

        # 255 is broadcast address
        if dest == 255 or src == 255:
            print("switch> Output on all ports")
            return

        # Check if dest is mapped to any port
        if dest in sat:
            print(f"switch> Output on port {sat[dest]}")
        else:
            print("switch> Output on all ports")

        # Check if src is mapped to any port
        if src not in sat or port != sat[src]:
            sat[src] = port

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: ./python3 switch [n: # of ports available]")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except:
        print("Usage: ./python3 switch [n: # of ports available]")
        sys.exit(1)

    switch = Switch(n)

    while True:
        vals = switch.get_input()

        if vals == 'a':
            switch.print()
        elif vals == "exit":
            sys.exit(0)
        else:
            switch.run(vals)