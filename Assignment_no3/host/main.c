// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie


#include "host.h"
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

q_a_pair questions_answers[QUESTIONS_PER_ROUND];
int port = 8080;
int sock;
int connection;
char* ip = "127.0.0.1";

void sigint_handler(int sig_num) {
    printf("\nExiting...\n");

    send(connection, "", 0, 0);
    close(connection);    
    close(sock);
    
    exit(0);
    }

int main(int argc, char** argv) {
    int opt;
    while((opt = getopt(argc, argv, "hp:i:")) != -1) {
        switch(opt) {
            case 'h':
                fprintf(stderr, "Usage: %s [-p port] [-i ip]\n", argv[0]);
                return 1;
            case 'p':
                port = atoi(optarg);
                break;
            case 'i':
                ip = optarg;
                break;
            default:
                fprintf(stderr, "Usage: %s [-p port] [-i ip]\n", argv[0]);
                return 1;
        }
    }

    sock = -1;
    signal(SIGPIPE, SIG_IGN);

    if (start_server(ip, port, &sock)) {
        fprintf(stderr, "Server wasn't able to start!\n");
        return 1;
    }

    while (1) {
        connection = -1;
        
        if (get_connection(sock, &connection)) {
            fprintf(stderr, "Critical error during connection");
        }

        if (get_questions(questions_answers)) {
            fprintf(stderr, "Couldn't get questions\n");
            return 1;
        }

        if (quiz(connection, questions_answers)) {
            fprintf(stderr, "Error during quiz\n");
            return 1;
        }
        
    }

    close(sock);
    return 0;
}