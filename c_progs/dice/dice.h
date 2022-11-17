#include <time.h>
#include <inttypes.h>
#include "input_parser.h"

//maximum array sie of the program is 32 767 
#define ARR_MAX SHRT_MAX

/**16-bit positive random generator with random order of elements, just because. Uses dynamic memory allocation inside -> to-do: change the passed parameters to pointers?**/
void generate(uint16_t count, uint16_t min, uint16_t max);

