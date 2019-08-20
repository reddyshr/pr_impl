#include "tcp_client.h"

int recv_data(int client_socket, char* rx_buffer_out) {

	int len = recv(client_socket, rx_buffer_out, 12, 0);

	if (len < 0) {
		printf("Failed to receive data\n");
		return -1;
	} else if (len == 0) {
		printf("Connection Closed\n");
		return -1;
	} else {
		rx_buffer_out[len] = 0;
	}

	return 0;

}

int send_data(int client_socket, char* data) {

	int send_status = send(client_socket, data, strlen(data), 0);
	if (send_status < 0) {
		perror("Failed to send: ");
		return -1;
	}

	return 0;

}

int init_tcp_client(int &client_socket_out) {

	int status;
	struct addrinfo hints;
	struct addrinfo *res;

	memset(&hints, 0, sizeof(hints));

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	status = getaddrinfo(SERVER_IP_ADDR, PORT, &hints, &res);
	if (status != 0) {
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
		return(-1);
	}

	int clientfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (clientfd < 0) {
		perror("Failed to create socket: ");
		return -1;
	}
	printf("Create Client Socket Success");

	int connect_val = connect(clientfd, res->ai_addr, res->ai_addrlen);
	if (connect_val < 0) { 
		perror("Failed to connect: ");
		return -1; 
	} 

	client_socket_out = clientfd;
   	printf("Successfully Connected Socket\n");
	return 0;	
}

int close_tcp_client(int client_socket) {
	close(client_socket);
	printf("Closed Client Socket\n");
}

