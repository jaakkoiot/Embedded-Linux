#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>

//maximum input line is 64 characters, although no input of that length is actually respected in the program
#define LINE 64
//maximum data unit of the program is 32 767
#define MAX SHRT_MAX

//to-do: move range-validation of the user's input inside the read-function with passed pointers to already populated parameters -> cleaner main.c and more efficient
uint16_t read_positive_integer();
//atoi that doesn't exceed the maximum defined unit size
uint16_t myatoi(char *s);
