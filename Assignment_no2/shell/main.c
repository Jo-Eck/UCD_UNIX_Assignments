// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie
#include "shell_header.h"

char *line;
size_t len;
ssize_t lineSize;
char *current_directory;

int main(void) {
    signal(SIGINT, sigint_handler);
    current_directory = getenv("PWD");

    // Main loop
    while (1) {
        
        promt(current_directory);
        lineSize = getline(&line, &len, stdin);
        char **input = process_input(line, lineSize);

        // Check for EOF, exit or error
        if (feof(stdin) || strcmp(input[0], "exit") == 0) {
            printf("Exiting...\n");
            break;
        }

        if (strcmp(input[0], "cd") == 0) {
            current_directory = input[1] == NULL ? getenv("HOME") : input[1];

            if (chdir(current_directory) != 0) {
                perror("cd");
            }
        } else {
            // Check for redirection in the input list
            int f = -1;
            for (int i = 0; input[i] != NULL; i++) {
                if (strcmp(input[i], ">") == 0) {
                    f = open(input[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
                    input[i] = NULL;
                    break;
                }
            }
            execute_command(input, f);
        }

        free(input);
    }

    return 0;
}
