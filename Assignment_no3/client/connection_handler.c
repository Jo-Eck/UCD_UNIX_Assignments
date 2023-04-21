// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie

#include "client.h"

int connection;

int connect_to_server(){
    // Mutates the global variable connection to the socket file descriptor
    // Returns 0 on success, 1 on failure

    connection = socket(AF_INET, SOCK_STREAM, 0);
    if (connection == -1) {
        return 1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);

    printf("Trying to connect on: %d\n", server_port);
    if (connect(connection, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        close(connection);
        return 1;
    }

    printf("Connected to server %s:%d\n", server_ip, server_port);
    return 0;

}

int kill_connection(){
    send_msg("q");
    close(connection);
    return 0;
}