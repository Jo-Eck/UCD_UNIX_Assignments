// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie 
#include "shell_header.h"

pid_t pid, wpid;

void execute_command(char **sections, int redirect_file){

        pid = fork();
        if (pid == 0){
            if (redirect_file != -1){
                dup2(redirect_file, 1);
            }

            if (execvp(sections[0], sections) == -1){
                printf("Error executing command\n");
            }

            if (redirect_file != -1){
                close(redirect_file);
            }
        }else if (pid < 0){
            printf("Error forking\n");
        }
        
        // waiting fo the child process to finish
        // so it doesnt print the promt before the child process finishes
        
        else{

            wpid = wait(NULL);
        }
}