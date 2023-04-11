// Created by Jon Eckerth
// Student ID: 22209542
// Email: jon.eckerth@ucdconnect.ie

// [ ] use internet domain stream sockets
// [ ] will ask the client 5 questions 
//      [ ] one after another
// [ ] at the end a score will be calculated
// [ ] only the server has access to the questions
// [ ] the server randomly selects 5 questions
// [ ] the server takes two arguments (assuming cli parameters)
//      [ ] IP4 address
//      [ ] Port number
// [ ] Server will bind to this port
// [ ] Server will then print :
//      "<Listening on IP:PORT>
//      <Press ctrl-C to terminate>""
// [ ] wait for clients to connect if so will send:
//      "Welcome to Unix Programming Quiz!
//      The quiz comprises five questions posed to you one after the other.
//      You have only one attempt to answer a question.
//      Your final score will be sent to you after conclusion of the quiz.
//      To start the quiz, press Y and <enter>.
//      To quit the quiz, press q and <enter>."
// [ ] if  "q" terminate connection and goe back into waiting for connections
// [ ] if "Y" start quiz
// [ ] sends question, if question correct, send:
//      "Right Answer." 
// [ ] if incorrect send:
//      "Wrong Answer. Right answer is <xxx>."
// [ ] After the conclusion of the quiz, the server will send the following to theclient:
//      "Your quiz score is x/5. Goodbye!""


#include "host.h"
q_a_pair questions_answers[QUESTIONS_PER_ROUND];

int main() {

    int socket;
    int connection = -1; 


    if (server("127.0.0.1",1024, &socket)){
        fprintf(stderr, "Server wasnt able to start!\n");
        return(1);
    }

    
    get_connection(socket, &connection);


    if (get_questions(questions_answers)){
        fprintf(stderr, "Couldnt get questions\n");
        return(1);
    }

    for (int i = 0; i < QUESTIONS_PER_ROUND; i++){
        printf("%s\n", questions_answers[i].question);
        
        printf("The correct answer is: %s\n \n", questions_answers[i].answer);

    }
    
    

    return 0;
}