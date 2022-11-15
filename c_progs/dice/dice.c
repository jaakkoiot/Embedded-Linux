#include "dice.h"

void generate(uint16_t c, uint16_t ma, uint16_t mi){
	uint16_t count = c, max = ma, min = mi;
	bool unique = false, match = false;
	uint16_t num = 0, inclusions = 0;

	printf("Spewing random numbers between %d and %d:\n", min, max);
	
	//initialising an array the size of MAX + 1 will fit MAX amount of random integers inside
	uint16_t arr[ARR_MAX +1] = {0};
	bool checkmap[ARR_MAX +1] = {false};
	
	//seed rand
	srand(time(0));

	do{
		//generate number between min - max
		num = (rand() % (max - min + 1)) + min;

		if(checkmap[num] == false){
			arr[inclusions] = num;
			checkmap[num] = true;
			inclusions++;
		}

	}while(inclusions < count);
		
	printf("\n______________________________________\nPrinting spewage:\n\n");

	//print array of random integers
	for(int k = 0; k < inclusions; k++){
	       	if(arr[k] != 0){
			printf("#%d : %d\t", (k+1), arr[k]);
		}
	}

  return;
}


