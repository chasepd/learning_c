#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>

#define PORT 2222

void *handleNewConnection(void *vargp){
    int valread;
    int new_socket = *(int*)vargp;
    char hello_msg[] = "Hello, please send USER command for login\n";
    send(new_socket , hello_msg , strlen(hello_msg) , 0 );
        printf("Accepted new connection, hello msg sent\n");
        int cont = 1;
        while (cont){
            char buffer[1024] = {0};
            valread = read( new_socket , buffer, 1024);
            printf("Received: %s\n",buffer );
        }
    return NULL;
}

int main(int argc, char *argv[]){
	int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addr_len=sizeof(address);
    
    
    if (argc > 1) {
		printf("Too many arguments provided. Unable to interpret \"%s\"\n", argv[1]);
		return 1;
	}
	
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Created socket\n");        
    }
    
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))){
        perror("Setting socket options failed");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Set socket opts\n");        
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Bind successful\n");        
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    while (1){
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                            (socklen_t*)&addr_len))<0)
        {
                perror("accept");
                exit(EXIT_FAILURE);
        }
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handleNewConnection, &new_socket);
    }
    return 0;
}
