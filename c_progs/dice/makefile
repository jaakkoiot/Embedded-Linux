CC=gcc
CLAGS=-Wall -Wextra
EXE=Dice

all: mainapp

mainapp: input_parser.o dice.o main.o
	$(CC) $(CFLAGS) main.o input_parser.o dice.o -o $(EXE)

input_parser.o: input_parser.c
	$(CC) -c $(CFLAGS) input_parser.c -o input_parser.o

dice.o: dice.c
	$(CC) -c $(CFLAGS) dice.c -o dice.o

main.o: main.c
	$(CC) -c $(CFLAGS) main.c -o main.o

clean:
	rm a.out *.o $(EXE)

#What I previously used to create the executable Dice:

#dicemake: main.c input_parser.c dice.c
#		gcc *.c -Wall -Wextra -Wpedantic -o Dice
