$(info Makefile_started.)
CC=gcc
CFLAGS=-Wall
all: \src\test.exe

test.exe: test.o
	 gcc -o \src\test.exe \src\test.o

test.o: test.c
	 gcc -c \src\test.c
     
clean:
	 rm \src\test.o \src\test.exe