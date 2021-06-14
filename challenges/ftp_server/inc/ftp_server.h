#ifndef FTPSERVINCLUSION
#define FTPSERVINCLUSION

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>

#define DEFAULT_PORT 2222
#define TRUE 1
#define FALSE 0

#define EXIT_COMMAND 22

void handle_connection(int new_socket);
int handle_command(char message[1024]);

const char hello_msg[];
const char goodbye_msg[];

#endif