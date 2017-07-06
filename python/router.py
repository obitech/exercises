#!/usr/bin/python3
# router.py - Simulating a routing table

import ipaddress

def ip(addr):
    try:
        return ipaddress.ip_address(addr)
    except:
        pass

def get_ip():
    while True:
        try:
            inp = input("router> ")
            if inp == "exit":
                return "exit"

            for x in [int(x) for x in inp.split('.')]:
                if x < 0 or x > 255:
                    raise Exception
            return inp
        except:
            print("Please enter a valid IP address between 0.0.0.0 and 255.255.255.255.")

class Entry:
    def __init__(self, n, g, i):
        self.network = ipaddress.ip_network(n)
        self.gateway = ip(g)
        self.interface = i

class Router:
    table = {
        "default": Entry("134.109.192.254/32", "134.109.192.254", "eth0"),
        "127.0.0.0": Entry("127.0.0.0/8", "0.0.0.0", "lo"),
        "134.109.192.0": Entry("134.109.192.0/24", "0.0.0.0", "eth0"),
        "192.168.0.0": Entry("192.168.0.0/16", "0.0.0.0", "eth1"),
        "10.0.0.0": Entry("10.0.0.0/8", "134.109.192.23", "eth0"),
        "120.34.23.128": Entry("120.34.23.128/25", "192.168.23.47", "eth1")
    }

    def __init__(self):
        print("Enter an IP address to find route or 'exit' to quit.\n")

    def route(self, address):
        table = self.table
        gateway = table["default"].gateway
        interface = table["default"].interface

        for k, v in table.items():
            if k != "default":
                if ip(address) in v.network:
                    gateway = v.gateway
                    interface = v.interface

        print(f"{gateway} {interface}")

    def run(self):
        inp = get_ip()
        
        while inp != "exit":
            self.route(inp)
            inp = get_ip()    

if __name__ == "__main__":
    router = Router()
    router.run()