// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie 
#include "shell_header.h"

struct tm *info;
char buffer[80];
time_t rawtime;

void promt() {
    time_t rawtime;
    struct tm *info;
    char buffer[80];

    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 80, "%d/%m %H:%M", info);
    printf("[%s] # ", buffer);
}
