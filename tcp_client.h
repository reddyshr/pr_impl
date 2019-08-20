#ifndef PR_IMPL_TCP_CLIENT_H
#define PR_IMPL_TCP_CLIENT_H

#include <sys/socket.h> 
#include <sys/types.h>
#include <netdb.h>


#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <errno.h>

#include <string.h> 

#define PORT "8027"
#define SERVER_IP_ADDR "127.0.0.1"



int recv_data(int client_socket, char* rx_buffer_out);
int send_data(int client_socket, char* data);
int init_tcp_client(int &client_socket_out);
int close_tcp_client(int client_socket);


#endif