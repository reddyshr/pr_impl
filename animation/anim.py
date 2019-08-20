
import socket

def init_tcp_server():

	TCP_IP = "127.0.0.1"
	TCP_PORT = 8027
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((TCP_IP, TCP_PORT))
	s.listen(1)

	print("Waiting For Client to Connect...")
	conn, addr = s.accept()
	print('Connection address:', addr)

	return conn

def close_tcp_server(s):

	s.close()


def main():

	conn = init_tcp_server()
	BUFFER_SIZE = 1024

	data = conn.recv(BUFFER_SIZE)

	print(data)

	close_tcp_server(conn)

	print("Done")



main()



