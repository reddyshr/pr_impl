import socket


TCP_IP = '127.0.0.1'
TCP_PORT = 8027
MESSAGE = "YA BOI!"

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))
s.send(MESSAGE)
s.close()

