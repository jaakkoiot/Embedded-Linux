#include "../inc/dice.h"

void generate(uint16_t c, uint16_t ma, uint16_t mi) {
	uint16_t count = c, max = ma, min = mi;
	uint16_t num = 0;
	int inclusions = 0;

	//initialising dynamic array with size of count * uint16_t 
	uint16_t* arr = (uint16_t*)malloc((count + 1) * sizeof(uint16_t));
	bool checkmap[ARR_MAX];

	//initialise checkmap to false and array to 0
	for (uint16_t i = 0; i < ARR_MAX; ++i) {
		checkmap[i] = false;
	}

	//seed rand with current system time
	srand(time(NULL));

	do {
		//generate number between min - max, it is still a candidate without validation (enforce unique)
		num = (rand() % (max - min + 1)) + min;
		//check the number based on index of the check map
		if (checkmap[(num - min)] == false) {
			//if checkmap indicates the value is not present -> program attempts to copy it to the array in a safe manner: if it succeeds the checkmap is changed to true on position
			if(memcpy_safe(&arr[inclusions],sizeof(arr),&num,sizeof(uint16_t))){
				checkmap[(num - min)] = true;
				//inclusions is the final, incrementing index of the resulting array
				inclusions++;
			}else{
				fprintf(stderr, "Cannot access memory in copy operation.\n");
				return;
			}
		}
	} while (inclusions < count);

	printf("\n______________________________________\nPrinting spewage:\n\n");
	printf("Spewing %d random numbers between %d and %d:\n", count, min, max);

	for (int n = 0; n < inclusions; n++) {
		printf("%d:%d\n", n + 1, arr[n]);
	}

	free(arr);
	return;
}

int memcpy_safe(void* dst, size_t dst_size, void* src, size_t src_size){

	//validation: data to copy or source must not be 0 and sie of the destination must be large enough to hold data being copied
	if (src_size == 0){
		return 0;
	}
	
	if (src == NULL || dst_size < src_size){
        	/* zero the destination buffer */
        	memset(dst, 0, dst_size);
		
		return 0;
	}
	
	//after validation, the program can continue to use memcpy
	memcpy(dst, src, dst_size);
    	return 1;

}
