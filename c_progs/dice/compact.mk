CC=gcc
CFLAGS=-Wall -Wextra
INCLUDES=
EXE=Dice
OBJECTS=dice.o input_parser.o main.o

#magic with wildcards & implicit rules:
#implicit rules state to create each object from a c-file with the same name
#instead of a ariable for the program name, $@ could be used for the output name 'compact'
compact: $(OBJECTS)
	$(CC) -o $(EXE) $^


clean:
	rm *.o $(EXE)

clean_objects:
	rm *.o
