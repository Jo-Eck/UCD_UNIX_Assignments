// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie

#include "client.h"

char *server_ip = "127.0.0.1";
int server_port = 8080;
int child_pid;

void terminate(int sig)
{   
    kill_connection();
    kill(child_pid,SIGKILL);
    exit(0);
}


int main(int argc, char **argv) {

    signal(SIGINT, terminate);
    // Parse command line arguments if any
    // Default values as defined in client.h
    // -i for ip address
    // -p for port
    // -h for help
    
    int opt;
    while ( (opt = getopt(argc, argv, "hi:p:")) != -1) {
        switch (opt) {
            case 'i':
                server_ip = optarg;
                break;
            case 'p':
                server_port = atoi(optarg);
                break;
            case 'h':
                fprintf(stderr, "Usage: %s [-p port] [-i ip]\n", argv[0]);
                return 1;
        }
    }

    // Establishes connection to the server
    if (!connect_to_server()){
        perror("Cannot connect to server - Has the server been started?");
        EXIT_FAILURE;
    }
    
    //Splits client into receiver and sender
    child_pid = fork();


    if (child_pid > 0) {
        // Receiver loop
        while(1){
            rec_msg();
        }
    }else if (child_pid == 0){
        // Sender loop
        while(1){
                char message[BUFFER_MAX];
                fgets(message, BUFFER_MAX, stdin);

                if (message[strlen(message) - 1] == '\n') {
                    message[strlen(message) - 1] = '\0';
                }
                send_msg(message);
                memset(message, 0, BUFFER_MAX);

            }
        }

    else{
        perror("Fork failed");
        EXIT_FAILURE;
    }
}