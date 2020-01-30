#ifndef _DAEMON_HEADER_H
#define _DAEMON_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080 
#define ERR_VAL -1
#define SUCCESS 0
#define BUFFER_SZ 1024

int CreateSocket(int *Sockfd);
int CreateLogFile(void);

#endif
