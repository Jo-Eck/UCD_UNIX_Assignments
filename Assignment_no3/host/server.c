// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie
#include "host.h"


int start_server(char* ip_addr,int port, int *fd){

    // creating the socket
    *fd = socket(AF_INET, SOCK_STREAM, 0);

    // creating and filling and binding the port and address to the socket
    struct  sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(struct  sockaddr_in));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(ip_addr);
    serverAddress.sin_port = htons(port);

    int rc = bind(
        *fd,
        (struct sockaddr *)&serverAddress,
        sizeof(struct sockaddr)
    );   
    
    // Set the socket to listen for connections
    if (listen(*fd, 10) == -1) {
        perror("Error in listen");
        return 1;
    }
    printf("<Listening on %s:%d> \n", ip_addr, port);
    printf("<Press ctrl-C to terminate> \n");
    return 0;
}

int get_connection(int socket, int *connection_fd) {
    struct sockaddr_storage claddr;
    char host[1024], service[32];

    // Continuously wait for a connection
    while (1) {
        socklen_t addrlen = sizeof(claddr);
    
        *connection_fd = accept(socket, (struct sockaddr *) &claddr, &addrlen);
        
        if (*connection_fd == -1) {
            perror("Error in accept");
            continue;
        }

        // Get the address of the connected client and print it
        if (getnameinfo((struct sockaddr *) &claddr, addrlen,
                        host, 1025, service, 32, 8) == 0) {
            printf("Connection established with: %s:%s\n", host, service);
        } else {
            fprintf(stderr, "Error in getnameinfo\n");
            return 1;
        }
        
        break;
    }
    return 0;
}

int send_message(int connection, char* message){
    send(connection, message, strlen(message), 0);

    // Message terminator
    send(connection, "\r\n\r\n", 4, 0);
}
