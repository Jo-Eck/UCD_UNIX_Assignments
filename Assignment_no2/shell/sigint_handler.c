// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie 
#include "shell_header.h"

void sigint_handler(int sig_num) {
    signal(SIGINT, sigint_handler);
    printf("\n");
    promt();
    sleep(0.01);
    fflush(stdout);
}
