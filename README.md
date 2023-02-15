# UCD_Assignment_UNIX_No1

This Repository contains the the first graded assignment for the UNIX Programming course at UCD.

## Assignment 1 Details and Submission

The Unix utilities head and tail output the first and last parts of files respectively.
Your assignment is to implement your own version of these utilities in C.
You will submit your code to file submission.

- [X] Implement either head or tail, even or odd line listing (your choice).
- [X] You should work independently, you may consult with each other but submit code that is entirely yours. You are free to use any code from lectures and labs. Feel free to read the source code of GNU head and tail but please don’t submit code based directly on this.
- [X] Submit a single .c file. Name the file exactly assign1-XXX.c where XXX is your student number.
- [X] In the comment block at the top, explain concisely what the program does and include your name, student number and email address.
- [X] Note in the comment block how well you completed the task (eg. Works completely, or x and y work, but z does not).

NOTE: It is very important to add meaningful comments to your code explaining what every block of the code performs.
Use getopt to accept the following optional parameters:
{ head | tail } [OPTION ] . . . [ FILE ]
Print the first | last 10 lines of FILE to standard output.
If no FILE is provided, then read standard input.
You are supposed to implement the following options :
-n K output the first|last K lines
-V Output version info: Your name, email, student number.
-h display all options ( something like this text describing the options ) and exit the application
-e|-o print even|odd lines.

Example: Consider a given input file named input.txt with the following content:
1
2
3
4
5
6
7
8
9
The output for head -n 3 -e input.txt looks like this:
2
4
6
and head -n 3 -o input.txt will display:
1
3
5

and head -h or tail -h will display:
-n K output the last K lines
-V Output version info: Your name, email, and student number.
-h display this
-e print even lines.
-o print odd lines.

Check-list:
• Submit the code to the assignment submission.
-Ensure you press “Submit all and finish” before the deadline.
• Name your file as specified.
• Make good use of lecture notes and labs.
