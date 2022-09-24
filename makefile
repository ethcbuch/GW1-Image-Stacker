# Name: Ethan Buchanan and Hunter Johnson
# File: Makefile for Image Stacker
# Date: 9/24/22


CC = g++
TARGET = stacker
CFLAGS = -g -Wall -Wextra
# Complies showing all errors and warnings

all: stacker

# List the object files needed to create the executable file.

$(TARGET):	 main.o Stacker.o
	$(CC) $(CFlags) -o $(TARGET) main.o Stacker.o

# Creates the rules need to link everything to main

main.o: main.cpp Stacker.h
	$(CC) $(CFLAGS) -c main.cpp

# Creates the rules for Vector.o

Stacker.o:	Stacker.cpp Stacker.h
	$(CC) $(CFLAGS) -c Stacker.cpp

# Creates a blank slate (done by 'make clean')

clean:
	$(RM) stacker *.o *~
