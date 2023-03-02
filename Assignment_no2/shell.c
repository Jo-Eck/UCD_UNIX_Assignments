#include "shell_header.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){
    char *line = "";
    size_t len = 0;
    ssize_t lineSize = 0;

    while(line[0] != 'q' ){
        printf("Enter a line: ");
        lineSize = getline(&line, &len, stdin);
        line[lineSize - 1] = '\0';
        printf("You entered %s, which has %zu chars.\n", line, lineSize - 1);
    }
    free(line); 
    return 0;
}