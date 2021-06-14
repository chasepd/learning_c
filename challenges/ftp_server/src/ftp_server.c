
#include "../inc/ftp_server.h"

const char hello_msg[] = "Hello, please send command. Send HELP for list of commands.";

const char goodbye_msg[] = "BYE";

int main( int argc, char *argv[] ){
	int server_fd, new_socket, port;
    struct sockaddr_in address;
    int opt = 1;
    int addr_len=sizeof(address);
    
    if (argc > 2) {
		printf("Too many arguments provided. Only valid argument is port number.\n");
		return 1;
	}
    else if (argc == 2){
        port = atoi(argv[1]);        
    }
    else{
        port = DEFAULT_PORT;
    }

    printf("Starting on port %i\n", port);
	
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
    address.sin_port = htons(port);

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
    
    while (TRUE){
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                            (socklen_t*)&addr_len))<0)
        {
                perror("accept");
                exit(EXIT_FAILURE);
        }

        handle_connection(new_socket);
        close(new_socket);
    }
    return 0;
}

void handle_connection(int new_socket){
    int value_read;
    char buffer[1024] = {0};
    value_read = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);
    send(new_socket, hello_msg, strlen(hello_msg), 0 );
    printf("Hello message sent\n");

    while(TRUE){
        value_read = read(new_socket, buffer, 1024);
        int result = handle_command(buffer);

        if(result == EXIT_COMMAND){
            send(new_socket, goodbye_msg, strlen(goodbye_msg), 0);
            break;
        }
    }
}

int handle_command(char message[1024]){
    return EXIT_COMMAND;
}
