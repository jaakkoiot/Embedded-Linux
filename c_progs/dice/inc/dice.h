#include <time.h>
#include <inttypes.h>
#include "../inc/input_parser.h"

//maximum array sie of the program is 32 767 
#define ARR_MAX SHRT_MAX

/**16-bit positive random generator with random order of elements, just because. Uses dynamic memory allocation inside -> to-do: change the passed parameters to pointers?**/
void generate(const uint16_t *count, const uint16_t *min, const uint16_t *max);

//safe memcpy validating destination size and src / dst pointers. Returns 1 on succesful operation, 0 on failure
int memcpy_safe(void * dst, size_t dst_size, void * src, size_t src_size);
