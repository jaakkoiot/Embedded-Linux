#include "dice.h"

void generate(uint16_t count, uint16_t max, uint16_t min){
	bool unique = false, match = false;
	uint16_t num = 0, inclusions = 0;

	srand(time(0));
	printf("Spewing random:\n");
	
	//generating "count" amount of random numbers to the array
	uint16_t arr[MAX] = {0};
	for(;inclusions < count;){
		num = (rand() % (max - min + 1)) + min;
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


