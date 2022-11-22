basic: mainapp

mainapp: input_parser.o dice.o main.o
	gcc -Wall -Wextra  main.o input_parser.o dice.o -o Dice

input_parser.o: input_parser.c
	gcc -c -Wall -Wextra input_parser.c -o input_parser.o

dice.o: dice.c
	gcc -c -Wall -Wextra dice.c -o dice.o

main.o: main.c
	gcc -c -Wall -Wextra main.c -o main.o

clean:
	rm *.o Dice

