CC=gcc
CFLAGS=-Wall -Wextra
INCLUDES=
EXE=Dice
OBJECTS=dice.o input_parser.o main.o

#magic with wildcards & implicit rules:
compact: $(OBJECTS)
	$(CC) -o $(EXE) $^


clean:
	rm *.o $(EXE)

clean_objects:
	rm *.o
