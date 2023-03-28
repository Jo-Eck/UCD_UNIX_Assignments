CC = gcc
CFLAGS = -g -Wall
TARGET = assign2_22209542

all: $(TARGET)

$(TARGET): main.o prompt.o process_input.o execute_command.o sigint_handler.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o prompt.o process_input.o execute_command.o sigint_handler.o

main.o: main.c shell_header.h
	$(CC) $(CFLAGS) -c main.c

prompt.o: prompt.c shell_header.h
	$(CC) $(CFLAGS) -c prompt.c

process_input.o: process_input.c shell_header.h
	$(CC) $(CFLAGS) -c process_input.c

execute_command.o: execute_command.c shell_header.h
	$(CC) $(CFLAGS) -c execute_command.c

sigint_handler.o: sigint_handler.c shell_header.h
	$(CC) $(CFLAGS) -c sigint_handler.c

clean:
	rm -f *.o $(TARGET)
dist:
	rm -rf assign2_22209542-1.0
	mkdir assign2_22209542-1.0
	cp main.c prompt.c process_input.c execute_command.c sigint_handler.c shell_header.h Makefile assign2_22209542-1.0/
	tar czvf assign2_22209542-1.0.tar.gz assign2_22209542-1.0
	rm -rf assign2_22209542-1.0
