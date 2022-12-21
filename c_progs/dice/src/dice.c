#include "../inc/dice.h"

void generate(const uint16_t *count, const uint16_t *max, const uint16_t *min) {
	uint16_t num = 0;
	//inclusions is the incrementing index of the array that this function generates
	uint16_t inclusions = 0;

	//initialising the dynamic array with size of count * uint16_t - this will contain the generated numbers
	uint16_t* arr = (uint16_t*)malloc((*count + 1) * sizeof(uint16_t));
	
	//using a bitfield for checkmap
	uint16_t bit_field = 0x0000;

	//seed rand with current system time
	srand(time(NULL));

	do {
		//generate number between min - max, it is still only a candidate without validation (enforce to be unique)
		num = (rand() % (*max - *min + 1)) + *min;
		//check the number based on the check map
		if (!IS_SET(bit_field, num)) {
			//if checkmap indicates the value is not present -> program attempts to copy it to the array in a safe manner: if it succeeds the checkmap is changed to true on position
			if(memcpy_safe(&arr[inclusions],sizeof(arr),&num,sizeof(uint16_t))){
				SET(bit_field, num);
				inclusions++;
			}else{
				fprintf(stderr, "Cannot access memory in copy operation.\n");
				return;
			}
		}
	} while (inclusions < *count);

	printf("\n______________________________________\n\n");
	printf("Spewing %d random numbers between %d and %d:\n", *count, *min, *max);

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
} 



void SET(uint16_t BF, uint16_t N){
	BF |= ((uint16_t)0x0001 << N);
}
 
void CLR(uint16_t BF, uint16_t N){
        BF &= ~((uint16_t)0x0001 << N);
}

bool IS_SET(uint16_t BF, uint16_t N){
        return ((BF >> N) & 0x1);
}  



