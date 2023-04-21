// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie

#include "client.h"

const char *delimiter = "\r\n\r\n";

int send_msg(char *message){
    // Sends a message to the server
    // Returns 0 on success, 1 on failure

    if (connection == -1) {
        perror("Not connected to server");
        return 1;
    }

    if (send(connection, message, strlen(message), 0) == -1) {
        perror("Error sending message");
        return 1;
    }
    return 0;
}

int rec_msg(){
    // Receives a message from the server
    // Returns 0 on success, 1 on failure

    size_t delimiter_length = strlen(delimiter);
    char buffer[BUFFER_MAX];
    char c;
    ssize_t bytes_received;
    int index = 0;
    int delimiter_index = 0;

    if (connection == -1) {
        perror("Not connected to server");
        return 1;
    }

    while (1){
        if ((bytes_received = recv(connection, &c, 1, 0)) == -1) {
            perror("Error receiving data");
            terminate(0);
            return 1;
        } else if (bytes_received == 0) {
            if (index == 0) {
                printf("Server closed connection\n");
                terminate(0);
            }
            break;
        } else {
            buffer[index++] = c;
            if (c == delimiter[delimiter_index]) {
                delimiter_index++;
                if (delimiter_index == delimiter_length) {
                    index -= delimiter_length;
                    break;
                }
            } else {
                delimiter_index = 0;
            }
        }
    }

    buffer[index] = '\0';
    printf("%s", buffer);
    return 0;
}
