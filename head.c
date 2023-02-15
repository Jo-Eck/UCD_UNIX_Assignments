#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    
    // Declares the variables
    int opt;
    char even_or_odd = 'n';
    int num_lines = 10; 
    char * path;
    int i = 0;
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while((opt = getopt(argc, argv,":Vheon:")) != -1){

        switch(opt){

            case 'h':
            // Prints the help text
                printf(
                    "-n K output the first K lines. \n"
                    "-V Output version info: Your name, email, and student number. \n"
                    "-h display this. \n"
                    "-e print even lines. \n"
                    "-o print odd lines. \n"
                );
                return 1;

            case 'V':
            // Prints details about the author
                printf(
                    "Name: Jon Eckerth \n"
                    "Email: jon.eckerth@ucdconnect.ie \n"
                    "Student Number: XXXXXXXXXXXXXXXX \n"
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
                num_lines = atoi(optarg);d
                break;
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

    //  Reads the file line by line and prints it to stdout
    while ((read = getline(&line, &len, fp) != -1) &&  i < num_lines){
        i++;
        if (
            (even_or_odd == 'n') ||                 // If no flag is set, it will print all lines 
            (even_or_odd == 'o' && i%2 != 0) ||     // If the odd flag is set, it will print all odd lines
            (even_or_odd == 'e' && i%2 == 0)       // If the even flag is set, it will print all even lines
            ){
                printf ("%d: ", i) ;
                printf(line);
            }
    }
}


