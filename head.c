// This program is a simplified version of the head command in linux
// It can be used to print the first 10 lines of a file, or a specified number of lines
// It can also be used to print only the even or odd lines of a file
// It prints details about the author if the -V flag is used
// It prints the help text if the -h flag is used
// Created by Jon Eckerth 2023
// Student Number: 22209542
// Email: jon.eckerth@ucdconnect.ie
// 
// This program works completely on Fedora 36, but I have not tested it on any other OS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    
    // Declares the variables
    int opt;
    char even_or_odd = 'n';
    int num_lines = 10; 
    char * path = NULL;
    int i = 0;
    FILE *fp;

    while((opt = getopt(argc, argv,":Vheon:?")) != -1){

        switch(opt){

            case 'h':
            // Prints the help text
                printf(
                    "Usage: head [OPTION]... [FILE]... \n"
                    "-n K output the first K lines. \n"
                    "-V Output version info: Your name, email, and student number. \n"
                    "-h display this. \n"
                    "-e print even lines. \n"
                    "-o print odd lines. \n"
                    "Takes input from stdin if no file is provided. \n"
                );
                return 0;

            case 'V':
            // Prints details about the author
                printf(
                    "Name: Jon Eckerth \n"
                    "Email: jon.eckerth@ucdconnect.ie \n"
                    "Student Number: 22209542 \n"
                );
                break;
            
            case 'e':
            // Sets the even_or_odd flag to even, so it will only print the even lines
            // if the flag as already been set to odd it will throw an error

                if (even_or_odd == 'o'){ 
                    fprintf(stderr, 
                        "ERROR: Both odd and even lines where requested!"
                        "Please choose only one or none at all \n"
                    );
                    return -1;
                }
                even_or_odd = 'e';
                break;

            case 'o':
            // Sets the even_or_odd flag to odd, so it will only print the even lines
            // if the flag as already been set to even it will throw an error
                if (even_or_odd == 'e'){ 
                    fprintf(stderr, 
                        "ERROR: Both odd and even lines where requested!"
                        "Please choose only one or none at all \n"
                    );
                    return -1;
                }
                even_or_odd = 'o';
                break;

            case 'n':
            // Provides the opportunity to override the number of lines printed (baseline is ten)
            // If a 
                if (atoi(optarg)== 0){
                    fprintf(stderr, 
                        "ERROR: -n used but no number provided! \n"
                    );
                    return -1;
                }
                num_lines = atoi(optarg);
                break;

            case '?':
            // If an unrecognized flag is used, it will throw an error
                fprintf(stderr, "Unrecognized argument: %s \n", argv[optind-1]);
                return -1;
        }
    }
    
    // If the user has provided more than one path, it will throw an error
    if (optind + 1 <  argc){
        fprintf(stderr, "Unrecognized argument!\n");
        return -1;
    }

    // If no path is provided, it will read from stdin
    if (optind ==  argc){
        printf("Please provide a file path: \n");
        scanf("%s", path);
    }else{
        path = argv[optind];
    }

    // Opens the file
    fp = fopen(path, "r");
    
    // If the file is not found, it will throw an error
    if (fp == NULL) {
        fprintf(stderr, "File not found: %s \n", path);
        return -1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    //  Reads the file line by line and prints it to stdout
    while ((read = getline(&line, &len, fp) != -1) &&  num_lines > 0){
        i++;
        if (
            (even_or_odd == 'n') ||                 // If no flag is set, it will print all lines 
            (even_or_odd == 'o' && i%2 != 0) ||     // If the odd flag is set, it will print all odd lines
            (even_or_odd == 'e' && i%2 == 0)       // If the even flag is set, it will print all even lines
            ){
                printf(line);
                num_lines--;
            }
    }
    
    // If the file does not contain enough lines, it will throw an error
    if (num_lines > 0){
        fprintf(stderr, "ERROR: File does not contain enough lines! \n");
        fclose(fp);
        return -1;
    }

    // If everything went well, it will return 0 and close the file
    fclose(fp);
    return 0;
}