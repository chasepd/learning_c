#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 2222

int main( int argc, char *argv[] ){
	int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addr_len=sizeof(address);
    char buffer[1024] = {0};
    char hello_msg[] = "Hello, please send USER command for login";
    if (argc > 1) {
		printf("Too many arguments provided. No args needed.\n");
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
        valread = read( new_socket , buffer, 1024);
        printf("%s\n",buffer );
        send(new_socket , hello_msg , strlen(hello_msg) , 0 );
        printf("Hello message sent\n");
    }
    return 0;
}
