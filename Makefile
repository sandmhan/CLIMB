#CLIMB Makefile
#Author: Austin Sanders

#gnu c compiler
CC=gcc
#Compiler Flags
CFLAGS= -Wall -I./inc
#Objects
OBJ= main.o profile.o files.o
#Smelly Object Directory
ODIR = ./obj
#Source Directory
SDIR = ./src

climb : $(ODIR)/$(OBJ)
	$(CC) -o climb $(OBJ) $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c $(CFLAGS) $(SDIR)/*.c

#main.o : ./src/main.c 
#	$(CC) -c $(CFLAGS) ./src/main.c
#
#profile.o : ./src/profile.c ./inc/profile.h
#	$(CC) -c $(CFLAGS) ./src/profile.c
#
#files.o : ./src/files.c ./inc/files.h
#	$(CC) -c $(CFLAGS) ./src/files.c

clean:
	rm climb $(OBJ)
