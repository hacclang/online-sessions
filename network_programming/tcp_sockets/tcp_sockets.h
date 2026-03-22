#ifndef TCP_SOCKETS_H
#define TCP_SOCKETS_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void panic(const char *str);
int connect_to_server(char *ip,int port);

#endif
