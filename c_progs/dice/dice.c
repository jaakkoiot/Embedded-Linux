#include "dice.h"

void generate(uint16_t c, uint16_t ma, uint16_t mi){
	uint16_t count = c, max = ma, min = mi;
	uint16_t num = 0, inclusions = 0;

	printf("Spewing %d random numbers between %d and %d:\n",count, min, max);
	
	//initialising an array the size of MAX + 1 will fit MAX amount of random integers inside
	uint16_t arr[count];
	bool checkmap[count];

	//initialise checkmap to false
	for(int i = 0; i < count; ++i ){
		checkmap[i] = false;
	}
	
	//seed rand
	srand(time(0));

	do{
		//generate number between min - max
		num = (rand() % (max - min + 1)) + min;

		//check the number based on index of the check map
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


