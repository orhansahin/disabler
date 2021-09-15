# -*- MakeFile -*-

CC = gcc
CFLAGS = -Wall
LIBS = -lm


xinput: main.o xinput.o
	$(CC) $(CFLAGS) $(LIBS) main.o xinput.o -o xinput

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

xinput.o: xinput.c inc/xinput.h
	$(CC) $(CFLAGS) -c xinput.c

clean:
	rm -f *.o xinput