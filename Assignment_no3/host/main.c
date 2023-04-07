// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie

#include "host.h"
q_a_pair questions_answers[QUESTIONS_PER_ROUND];

int main() {

    if (server()){
        fprintf(stderr, "Server wasnt able to start!\n");
        return(1);
    }

    if (get_questions(questions_answers)){
        fprintf(stderr, "Couldnt get questions\n");
        return(1);
    }

    for (int i = 0; i < QUESTIONS_PER_ROUND; i++){
        printf("%d\n", questions_answers[i].location);
        printf("%s\n", questions_answers[i].question);
        printf("%s\n", questions_answers[i].answer);

    }
    
    

    return 0;
}