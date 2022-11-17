#include "dice.h"
#include "input_parser.h"

int  main( int argc, char *argv[] ){
	uint16_t count = 0, min = 0, max = 0;

	printf("Welcome to the positive spewer.\n\nCan generate at most %d random positive integers.\n\n", ARR_MAX);

	//Only at maximum 3 parameters are expected from command line
	if(argc >= 5){
		fprintf(stderr,"Too many input arguments. They are disregarded.\n");
	}
	if(argc == 4){
		/**Command line parameters: #1 count | #2 maximum of the random range | #3 minimum of the range **/
		count = myatoi(argv[1]);
		max = myatoi(argv[2]);
		min = myatoi(argv[3]);

		if(count > 0 && count <= (max-min+1) && count <= ARR_MAX){
			printf("Parameters from command line: count %d, max %d, min %d\n", count, max, min);
		}else{
			fprintf(stderr,"Error (count|max|min): invalid arguments from command line.\nFirst argument is count of numbers, second is max of range and third is min of range.\n");
			count = max = min = 0;
		}
	}else if(argc == 3){
		count = myatoi(argv[1]);
		max = myatoi(argv[2]);

		if(count > 0 && count <= ARR_MAX){
			printf("Parameters from command line: count %d, max %d, min %d\n", count, max, min);
		}else{
			
			fprintf(stderr,"Error (count|max): invalid arguments from command line.\nFirst argument is count of numbers, second is max of range and third is min of range.\n");
			count = max = 0;
		}
	}else if(argc == 2){
		count = atoi(argv[1]);
		if(count > 0 && count <= ARR_MAX){
			printf("Parameters from command line: count %d", count);
		}
	}
	
	while(count == 0 || max == 0 || min == 0){
		while(count == 0){
			printf("How many numbers to spew?\n");
			count = read_positive_integer();
		}
		while(max == 0){
			printf("Enter maximum of the range:\n");
			max = read_positive_integer();
		}
		while(min == 0){
			printf("Enter minimum of the range:\n");
			min = read_positive_integer();
			if(count > (max-min) && min < max && count < ARR_MAX){
				fprintf(stderr,"Range needs to fit %d unique integers!\nOnly %d integers can be generated.\nResetting parameters.\n\n", count, (max-min+1));
				max = min = count = 0;
				break; //prevent loop by breaking
			}else if(min > max){
				fprintf(stderr,"Minimum cannot be over maximum of %d.\n Resetting range.\n\n", max);
				max = min = count = 0;
				break; //break needs to be called here as the min > max will otherwise cause a loop
			}
		}
	}
	
	printf("Maximum %d | Minimum: %d | Count: %d\n", max, min, count);
	
	generate(count, max, min);	

	return 0;
}
