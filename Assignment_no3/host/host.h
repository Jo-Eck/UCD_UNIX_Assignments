// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>


#define QUESTIONS_PER_ROUND 5
#define AMOUNT_OF_QUESTIONS 42
#define MAX_ANSWER_LENGTH 1000

typedef struct  q_a_pair{
    int location;
    char * question;
    char * answer;
} q_a_pair;



int start_server();
int get_questions();
int get_connection();
int quiz();
char* to_lower();
int send_message();