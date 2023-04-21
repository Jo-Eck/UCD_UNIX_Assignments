# Unix Programming Assignment 3

## Description

This is a simple server and client for a quizz game. Both are written in C and use sockets for communication.
Per requirement, the server is a single threaded application.

## How to run

### Server

Navigate to the server folder and run the following command to compile and run the server:

```bash
cd host
make run
```

alternatively, you can compile and run the server manually:

```bash
cd host
make
./quiz_server -p 64523 -i 127.0.0.1
```

### Client

Same goes for the client. Navigate to the client folder and run the following command to compile and run the client:

(make sure the server is running before running the client)

```bash
cd client
make run
```

manually:

```bash
cd client
make
./quiz_client -p 64523 -i 127.0.0.1
```

### Assignment checklist

- [X] use internet domain stream sockets
- [X] will ask the client 5 questions
- [X] at the end a score will be calculated
- [X] only the server has access to the questions
- [X] the server randomly selects 5 questions
- [X] the server takes two arguments (assuming cli parameters)
    - [X] IP4 address
    - [X] Port number
- [X] Server will bind to this port
- [X] Server will then print :
    -           <Listening on IP:PORT>
    -           <Press ctrl-C to terminate>
- [X] wait for clients to connect if so will send:
    - Welcome to Unix Programming Quiz! The quiz comprises five questions posed to you one after the other. You have only one attempt to answer a question. Your final score will be sent to you after conclusion of the quiz. To start the quiz, press Y and \<enter>. To quit the quiz, press q and \<enter>.
    - [X] if  "q" terminate connection and goe back into waiting for connections
    - [X] if "Y" start quiz
- [X] sends question, if question correct, send:
-      "Right Answer." 
- [X] if incorrect send:
-      "Wrong Answer. Right answer is <xxx>."
- [X] After the conclusion of the quiz, the server will send the following to the client:
-      "Your quiz score is x/5. Goodbye!""