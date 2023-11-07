CC=gcc
SOURCEFILES=./src/main.c
OUTFILE=main
SDL2CONFIG=-IC:/msys64/ucrt64/bin/../include -IC:/msys64/ucrt64/bin/../include/SDL2  -LC:/msys64/ucrt64/bin/../lib -lmingw32 -mwindows -lSDL2main -lSDL2
DEBUGGER=gdb

all:
	$(CC) $(wildcard src/*.c) -o $(OUTFILE) $(SDL2CONFIG)
	./main | cat
