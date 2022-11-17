#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>

#define LINE 64
#define MAX SHRT_MAX

uint16_t read_positive_integer();
uint16_t myatoi(char *s);
