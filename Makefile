#CLIMB Makefile
#Author: Austin Sanders

#gnu c compiler
CC=gcc
#Compiler Flags
CFLAGS= -Wall -I./inc
#Objects
OBJ= main.o profile.o files.o

climb : $(OBJ)
	$(CC) -o climb $(OBJ) $(CFLAGS)

main.o : ./src/main.c 
	$(CC) -c $(CFLAGS) ./src/main.c

profile.o : ./src/profile.c ./inc/profile.h ./inc/files.h
	$(CC) -c $(CFLAGS) ./src/profile.c

files.o : ./src/files.c ./inc/files.h
	$(CC) -c $(CFLAGS) ./src/files.c

clean:
	rm climb $(OBJ)
