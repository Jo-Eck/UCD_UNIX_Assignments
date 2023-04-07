// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie

#include <stdio.h>
#include <stdlib.h>

#define QUESTIONS_PER_ROUND 5
#define AMOUNT_OF_QUESTIONS 42

typedef struct  q_a_pair{
    int location;
    char * question;
    char * answer;
} q_a_pair;


int server();
int get_questions();


    