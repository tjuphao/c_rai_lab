#ifndef HELLO_H
#define HELLO_H

#include <stdint.h>

typedef int64_t INT_64;

void say_hello(void);
int add(int a, int b);
int divide(int a, int b, int *resultPtr);
INT_64 subtract(INT_64 a, INT_64 b);

#endif