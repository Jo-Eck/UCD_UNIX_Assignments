CC = gcc
CFLAGS=-g -Wall
TARGET = quiz_client

all: $(TARGET)

$(TARGET): main.o connection_handler.o message_handler.o	
	$(CC) $(CFLAGS) -o $(TARGET) main.o connection_handler.o message_handler.o

main.o: main.c  client.h
	$(CC) $(CFLAGS) -c main.c

connection_handler.o: connection_handler.c client.h
	$(CC) $(CFLAGS) -c connection_handler.c

message_handler.o: message_handler.c client.h
	$(CC) $(CFLAGS) -c message_handler.c

clean:
	rm -f *.o $(TARGET)

run: ${TARGET}
	clear	
	./${TARGET}
	make clean > /dev/null