#include "dice.h"

void generate(uint16_t count, uint16_t max, uint16_t min){
	bool unique = false, match = false;
	uint16_t num = 0, inclusions = 0;

	printf("Spewing random numbers between %d and %d:\n", min, max);
	
	//initialising an array the size of MAX + 1 will fit MAX amount of random integers inside
	uint16_t arr[(MAX+1)] = {0};
	for(;inclusions < count;){

		//seed srand inside the generating loop with current system time
		srand(time(0));
		//generate number between min - max
		num = (rand() % (max - min + 1)) + min;

		//enforce to be unique: if a match is found the number will be discarded
		for(int n = 0; n < (sizeof(arr)/sizeof(uint16_t)); n++){
			if(arr[n] == num) match = true;
		}
		if(!match){
			arr[inclusions] = num;
			inclusions++;
		}
		match = false;
	}

	//print array of random integers
	for(int k = 0; k < ((sizeof(arr)/sizeof(uint16_t))-1); k++){
	       	if(arr[k] != 0){
			printf("#%d : %d\t", (k+1), arr[k]);
		}
	}

  return;
}


