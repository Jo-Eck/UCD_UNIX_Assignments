// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie 

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>



void promt();
void sigint_handler(int sig_num);
char **process_input(char *line, int lineSize);
void execute_command(char **sections, int redirect_file);
