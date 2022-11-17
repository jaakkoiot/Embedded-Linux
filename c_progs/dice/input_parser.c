#include "input_parser.h"

//reading 16-bit positive integers with no range checking as that is performed in the main.c
uint16_t read_positive_integer(){
	char input[LINE] = { 0 };
	uint16_t number = 0, len = 0;
	bool only_digits = true;
		
	while (number <= 0 || number > MAX || !only_digits) {
		only_digits = true;		
		
		//Using fgets inside the if-statement uses the return value in a nice manner as NULL results in an error message
		if(fgets(input, LINE, stdin) == NULL){
			fprintf(stderr,"Error reading user input.\n");
		}
		else{
			input[strcspn(input, "\n")] = 0;    //remove trailing newline
                   	len = strlen(input);
			for(int i = 0; i< (len-2); i++){
				if(!isdigit(input[i]) && only_digits){
					fprintf(stderr,"Input is not a number\nOnly positive integers under %d are allowed.\nTry again:\n",MAX);
					only_digits = false;
				}
			}
			if(only_digits){
				number = (int)strtol(input, NULL, 0);
				if(number > MAX || number < 1){
					printf("The given number is out of range! values between %d and %d are accepted.\nTry again:\n",1, MAX);
					only_digits = false;
				}
				
			}	
		}
	}
	return number;
}

//this custom atoi respects the program's maximum input
uint16_t myatoi(char *s){
	uint16_t result = 0, minus_check = *s == '-';
	while(isdigit(*s)){
		result = result * 10 + (*s++ - '0');
	}
	if(minus_check) result = 0;

	return result <= MAX ? result : 0;
	
}
