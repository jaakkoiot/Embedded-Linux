#include "../inc/dice.h"

void generate(uint16_t c, uint16_t ma, uint16_t mi) {
	uint16_t count = c, max = ma, min = mi;
	uint16_t num = 0;
	int inclusions = 0;

	printf("Spewing %d random numbers between %d and %d:\n", count, min, max);

	//initialising dynamic array with size of count * uint16_t 
	uint16_t* arr = (uint16_t*)malloc((count + 1) * sizeof(uint16_t));
	bool checkmap[ARR_MAX];

	//initialise checkmap to false and array to 0
	for (uint16_t i = 0; i < ARR_MAX; ++i) {
		checkmap[i] = false;
	}

	//seed rand
	srand(time(NULL));

	do {
		//generate number between min - max
		num = (rand() % (max - min + 1)) + min;

		//check the number based on index of the check map
		if (checkmap[(num - min)] == false) {
			if(memcpy_safe(&arr[inclusions],sizeof(arr),&num,sizeof(uint16_t))){
				checkmap[(num - min)] = true;
				inclusions++;
			}
		}
	} while (inclusions < count);

	size_t dataunit = sizeof(uint16_t);
	size_t size = (count + 1) * dataunit;

	printf("\nSize of data point is%lu\nSize of the generated array is: %lu\n", sizeof(uint16_t), size);
	printf("\n______________________________________\nPrinting spewage:\n\n");

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
        	/* zeroe the destination buffer */
        	memset(dst, 0, dst_size);
		
		return 0;
	}
	
	//after validation, the program can continue to use memcpy
	memcpy(dst, src, dst_size);
    	return 1;

}
