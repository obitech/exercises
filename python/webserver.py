#!/usr/bin/python3

import socket
import sys
import datetime
import traceback
import re

"""
The Page class is a very basic template enginge to create HTML responses.
Use body() to glue it all together!
"""
class Page:
    title = ""

    def __init__(self, title="Hello World"):
        self.title = title

    def header(self, msg=""):
        if not msg:
            msg = self.title

        header = (
            "<html><head>",
            f"<title>{msg}</title></head>")

        return "".join(header)

    def link(self, tup):
        if not tup:
            return ""

        link, style, text = tup;
        out = ""

        if style == "":
            out = f"<a href='{link}'>{text}</a>"
        else:
            out = f"<a href='{link}' style='{style}'>{text}</a>"

        return out

    def p(self, msg=""):
        if not msg:
            return ""

        return f"<p>{msg}</p>"

    def h1(self, msg=""):
        if not msg:
            return ""

        return f"<h1>{msg}</h1>"

    def nav_bar(self):
        bar = (
            "<div style='height:25px; width:100%'>", 
            self.link(("/", "", "Home")),
            self.link(("/email", "margin-left: 25px","Show emails")),
            self.link(("/logout", "margin-left: 25px", "Shut down")),
            "</div>")

        return " ".join(bar)

    def get_home(self, nr_emails = 0):
        out = (
            self.h1("Welcome!"),
            self.p(f"You have {self.link(('/email', '', str(nr_emails)))} new emails!")
            )

        out = self.body("".join(out))

        return out

    def get_error(self, code):
        if code == 404:
            return self.body(self.h1("404 - Page not found"))
        elif code == 500:
            return self.body(self.h1("500 - Internal Server Error"))
        else:
            return ""

    # Arg needs to be tuple with email data
    def get_email(self, arg=""):
        out = [self.h1("Your mail:")]

        if arg is not "":
            tmp = list(arg)

            for mail in tmp:
                src, dest, date, subject, msg = mail
                out.append(self.p(f"<b>From:</b> {src}<br><b>To:</b> {dest}<br><b>Date sent:</b> {date}"))
                out.append(self.p(f"<br><b>Subject:</b> {subject}"))
                msg = msg[1:].replace("\n", "<br>")
                out.append(self.p(f"<br>{msg}"))
                if mail is not tmp[-1]:
                    out.append("<hr>")
        else:
            out.append(self.p("Nothing to see here!"))

        return self.body("".join(out))

    def get_bye(self):
        return self.body(self.h1("Goodbye! &#x2665") + self.p("Webserver shut down."))

    # Assembles all parts into valid HTML 'file'
    def body(self, content):
        return f"<!DOCTYPE html>{self.header()}<body>{self.nav_bar()}{content}</body></html>" + "\r\n"

"""
The Mail class handles everything regarding email:
connect to POP server, parse/format responses, etc
"""
class Mail:
    nr = 0
    data = []

    conn = ()
    auth = ()

    def __init__(self, conn, auth):
        self.conn = conn
        self.auth = auth

        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            if self.connect(s):
                # Gets current number of emails
                self.nr = self.nr_emails(s)
                self.data = []

                # Populates data list with emails as tuples
                if self.nr != 0:
                    for x in range(1, self.nr + 1):
                        print(f">>> Retrieving ID {x}:")
                        self.data.append(self.format_email(self.get_email(s, x)))
                        print(">>> Email retrieved and added to data array")
            else:
                print(">>> Unable to connect to POP3 Server.")

    # Returns true if connected & logged into POP server
    def connect(self, sock):
        try:
            sock.connect(self.conn)
            print(Webserver.recvall(sock))
            user, pw = self.auth
            out = (f"USER {user}\r\n", f"PASS {pw}\r\n")
            print(">> Sending: ")
            #print(out)

            sock.sendall(out[0].encode())
            print(f">> Received {Webserver.recvall(sock)}")
            sock.sendall(out[1].encode())
            print(f">> Received {Webserver.recvall(sock)}")

            return True
        except:
            print(f">> Error: {traceback.format_exc()}")
            return False

    # Returns tuple of specific email in nicer format
    def format_email(self, content):
        tmp = content.decode().replace("\t", "").split("\r\n")

        for x in range(len(tmp)):
            if "Return-Path" in tmp[x]:
                src = tmp[x].split(" ")[1]
                src = re.sub(r"(<|>)", "", src)
            if "To:" in tmp[x]:
                dest = tmp[x].split(" ")[1]
            if "Date:" in tmp[x]:
                date = " ".join(tmp[x].split(" ")[1:])
            if "Subject:" in tmp[x]:
                subject = " ".join(tmp[x].split(" ")[1:])
            if "X-UIDL:" in tmp[x]:
                index = x
                break

        msg = "\n".join(tmp[index + 2:-3])
        out = (src, dest, date, subject, msg)

        # print(out)
        return (out)


    # Returns specific email as string
    def get_email(self, sock, id):
        sock.send(f"retr {id}\r\n".encode())
        data = Webserver.recvall(sock)

        if "+OK" in data.decode():
            data = Webserver.recvall(sock)

        # print(data)
        return data

    # Returns nr of emails on srv
    def nr_emails(self, sock):
        sock.send("list\r\n".encode())
        data = Webserver.recvall(sock).decode()
        print(f">> Received {data}")
        print(f">> Ignored {Webserver.recvall(sock).decode()}")

        return int(data.split(" ")[1])

"""
This server will use Mail class to retrieve email from POP and Page class
to render HTML and send via HTTP (sockets). Since there is no caching, Mails
will get polled on every GET request
"""
class Webserver:
    port = 80
    host = ""

    pop_conn_tup = ()
    pop_auth_tup = ()

    BUFFER = 32768
    TIMEOUT = 10

    pages = {
        404: "Error - 404",
        500: "Error - 500",
        "/": "Home", 
        "/logout": "Shutdown Server", 
        "/email": "Your email"}

    mails = None

    def __init__(self, web, pop_conn, pop_auth):
        self.host, self.port = web
        self.pop_conn_tup = pop_conn
        self.pop_auth_tup = pop_auth

    def run(self):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.bind((self.host, self.port))
            s.listen(1)
            print(f">> Listening on port {self.port}...")
            while True:
                conn, addr = s.accept()
                data = self.recvall(conn)

                if not data:
                    conn.close()
                    break

                print(">> Received: ")
                print(data)

                try:
                    request = self.parse_http(data)

                    # Shuts down server
                    if request == "/logout":
                        out = Page("Goodbye!")
                        out = str(self.get_header() + out.get_bye()).encode()                
                        print(">> Sending:")
                        print(out)
                        conn.sendall(out)
                        conn.close()
                        break
                    else:
                        status, response = self.get_page(request)
                        out = str(self.get_header(status) + response).encode()

                # All exceptions will return 500 Error page
                except:
                    out = Page(self.pages[500])
                    out = str(self.get_header(500) + out.get_error(500)).encode()
                    print(f">> Exception caught: {traceback.format_exc()}")

                print(">> Sending:")
                print(out)
                conn.sendall(out)
                conn.close()

        print(">> Shutting down server.")

    # Assemble specific page and return as string
    def get_page(self, path):
        if path in self.pages:
            out = Page(self.pages[path])
            mails = Mail(self.pop_conn_tup, self.pop_auth_tup)

            # Mail: Display all emails
            if path == "/email":
                # print(mails.data)
                return (200, out.get_email(mails.data))
            else:
                # Home: Display number of emails
                return (200, out.get_home(mails.nr))
        else:
            out = Page(self.pages[404])
            return (404, out.get_error(404))


    @classmethod
    # Returns string of data received by socket
    def recvall(self, sock):
        data = b""

        while True:
            part = sock.recv(self.BUFFER)
            data += part

            if len(part) < self.BUFFER:
                break

        return data

    # Returns path requested by GET
    def parse_http(self, req):
        data = req.decode().split("\r\n")
        path = data[0].split(" ")[1]
        return path

    # Return specific header as string
    def get_header(self, status=200):
        status_dir = {
            200: "OK",
            404: "Not found",
            500: "Internal Error" }
      
        header = [ 
            f"HTTP/1.1 {status} {status_dir[status]}", 
            datetime.datetime.now().strftime("%a, %d %b %Y %H:%M:%S"),
            "Server: Python/4.2 (custom)",
            "Content-Type: text/html; encoding=utf8",
            "", "" ]

        return "\r\n".join(header)

if __name__ == "__main__":
    # TCP Connection details: (host, port)
    tcp_conn = ()
    
    # POP Connection details: (host, port)
    pop_conn = ()

    # POP authentication details: (user, password)
    pop_auth = ()

    srv = Webserver(tcp_conn, pop_conn, pop_auth)
    srv.run()