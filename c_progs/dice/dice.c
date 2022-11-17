#include "dice.h"

void generate(uint16_t c, uint16_t ma, uint16_t mi){
	uint16_t count = c, max = ma, min = mi;
	uint16_t num = 0, inclusions = 0;

	printf("Spewing %d random numbers between %d and %d:\n",count, min, max);
	
	//initialising an array the size of MAX
	uint16_t* arr;
       	arr=(uint16_t*)malloc(count*sizeof(uint16_t));
	bool checkmap[count];

	//initialise checkmap to false and array to 0
	for(uint16_t i = 0; i < count; ++i ){
		checkmap[i] = false;
	}
	
	//seed rand
	srand(time(NULL));

	do{
		//generate number between min - max
		num = (rand() % (max - min + 1)) + min;
		
		//check the number based on index of the check map
		if(checkmap[(num-min)] == false){
			memcpy(&arr[inclusions],&num,sizeof(uint16_t));
			checkmap[(num-min)] = true;
			inclusions++;
		}
	}while(inclusions < count);

	printf("\n______________________________________\nPrinting spewage:\n\n");

	for(uint16_t n = 0; n < count; n++){
		printf("%d:%d\t",n+1,arr[n]);
	}

	free(arr);
  return;
}


