// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <signal.h>

extern int connection;
extern char *server_ip;
extern int server_port;

int connect_to_server();
int kill_connection();
int send_msg(char *message);
int rec_msg();
void terminate(int sig);

#define BUFFER_MAX 1024