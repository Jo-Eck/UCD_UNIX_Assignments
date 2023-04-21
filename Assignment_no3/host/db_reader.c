// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie

#include "host.h"
#include "QuizDB.h"
 

int get_questions(q_a_pair questions_answers[QUESTIONS_PER_ROUND]){
    srand(time(NULL));

    for (int i = 0; i < QUESTIONS_PER_ROUND; i++){
        q_a_pair qa;

        // Picking a random location of the question and answer
        qa.location = rand() % (AMOUNT_OF_QUESTIONS + 1);

        // Checking if the location has already been picked
        for (int j = 0; j < i; j++){
            // If so pick a new location
            if (qa.location == questions_answers[j].location){
                qa.location = rand() % (AMOUNT_OF_QUESTIONS + 1);
                j = 0;
            }
        }
        
        // Setting the question and answer based on the location
        qa.answer = QuizA[qa.location];
        qa.question = QuizQ[qa.location];

        // Adding the question and answer to the array
        questions_answers[i] = qa;
    }

    return 0;
}
