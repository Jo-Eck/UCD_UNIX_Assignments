// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

#define QUESTIONS_PER_ROUND 5
#define AMOUNT_OF_QUESTIONS 42

typedef struct  q_a_pair{
    int location;
    char * question;
    char * answer;
} q_a_pair;



int server();
int get_questions();
int get_connection();


    