// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie 
#include "shell_header.h"

char **process_input(char *line, int lineSize){

    char *section;
    char **sections = malloc(sizeof(char *));
    int i = 0;
    
    // processing the line to command and arguments
    // removing the new line character at the end of the line
    line[lineSize - 1] = '\0';
        
    // splitting the line into command and arguments

    section = strtok (line," ");
    while (section != NULL){

        // adding the section string with an added null terminator
        sections[i++] = section + '\0';
        // updating the pointer and the index
        section = strtok (NULL, " ");
        // reallocating the sections array
        sections = realloc(sections, sizeof(char *) * (i + 1));
    }
    
    // adding the null terminator to the end of the sections array
    sections[i] = NULL;
    return sections;
}