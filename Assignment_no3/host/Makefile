CC = gcc
CFLAGS=-g -Wall
TARGET = quiz_server

all: $(TARGET)

$(TARGET): main.o server.o  db_reader.o quiz.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o server.o db_reader.o quiz.o

main.o: main.c  host.h
	$(CC) $(CFLAGS) -c main.c

server.o: server.c host.h
	$(CC) $(CFLAGS) -c server.c

db_reader.o: db_reader.c host.h QuizDB.h
	$(CC) $(CFLAGS) -c db_reader.c
	
quiz.o: quiz.c host.h QuizDB.h
	$(CC) $(CFLAGS) -c quiz.c

clean:
	rm -f *.o $(TARGET)

run: ${TARGET}
	clear
	./${TARGET}

	make clean > /dev/null
