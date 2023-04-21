// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie


#include "host.h"

char * welcome_message =  "Welcome to Unix Programming Quiz!\nThe quiz comprises five questions posed to you one after the other.\nYou have only one attempt to answer a question.\nYour final score will be sent to you after conclusion of the quiz. \nTo start the quiz, press Y and <enter>.\nTo quit the quiz, press q and <enter>.\n";
char * answer_incorrect = "Answer incorrect - the correct answer is '%s' you entered '%s'\n\n";
char buffer[MAX_ANSWER_LENGTH];
int hits = 0;

int quiz(int connection, q_a_pair questions_answers[QUESTIONS_PER_ROUND]){

    printf("sending welcome message\n");

    send_message(connection, welcome_message);


    while(1){
        memset(buffer, 0, MAX_ANSWER_LENGTH);
        recv(connection, buffer, MAX_ANSWER_LENGTH, 0);

        // checking if the user wants to quit
        // printf("buffer: '%s'\n", buffer);
        if (strcmp(buffer, "q") == 0) {
            printf("Client requested to quit\n");
            send_message(connection, "");            
            close(connection);     
            return 0;

        }else if (strcmp(buffer, "Y") == 0) {

            printf("starting quiz\n");
            break;

        } else {
            // If illegal input, send error message
            send_message(connection, "Please enter Y or q\n");
        } 
    }
    for (int i = 0; i < QUESTIONS_PER_ROUND; i++) {
            char *newstr = malloc(strlen(questions_answers[i].question) + 2);
            strcpy(newstr, questions_answers[i].question);
            strcat(newstr, "\n");

          
            send_message(connection, newstr);

            memset(buffer, 0, MAX_ANSWER_LENGTH);

            recv(connection, buffer, MAX_ANSWER_LENGTH, 0);


            if (strcmp(buffer, "q\n") == 0) {
                // If a client disconnects, close the connection
                printf("Client disconnected\n");
                break;
            }

            char *lower_buffer = to_lower(buffer);
            char *lower_answer = to_lower(questions_answers[i].answer);

            if (strcmp(lower_buffer, lower_answer) == 0) {
                send_message(connection, "Answer correct\n\n");
                hits++;

            } else {
                char * response;
                asprintf(&response, answer_incorrect, questions_answers[i].answer, lower_buffer);
                send_message(connection, response);
            }

        }

       
        char *score_msg = "Your score is %d/%d!\n";
        char score_buffer[38];
        sprintf(score_buffer, score_msg, hits, QUESTIONS_PER_ROUND);
        hits = 0;
        

        send_message(connection, score_buffer);
        close(connection);
}


char* to_lower(char* string) {
    size_t len = strlen(string);
    char * ret_string = malloc(len + 1);
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (string[i] != '\n') {
            ret_string[j++] = tolower((unsigned char)string[i]);
        }
    }
    ret_string[j] = '\0';
    return ret_string;
}

