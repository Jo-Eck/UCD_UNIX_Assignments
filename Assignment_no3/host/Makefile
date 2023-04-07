CC = gcc
CFLAGS=-g -Wall
TARGET = quiz

all: $(TARGET)

$(TARGET): main.o server.o  db_reader.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o server.o db_reader.o

main.o: main.c  host.h
	$(CC) $(CFLAGS) -c main.c

server.o: server.c host.h
	$(CC) $(CFLAGS) -c server.c

db_reader.o: db_reader.c host.h ../QuizDB.h

	$(CC) $(CFLAGS) -c db_reader.c

clean:
	rm -f *.o $(TARGET)

run: ${TARGET}
	#clear
	./${TARGET}

	make clean > /dev/null