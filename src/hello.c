#include <stdio.h>
#include "hello.h"

void say_hello(void) {
    printf("Hello, World!\n");
}

int add(int a, int b) {
    return a + b;
}

/* Returns 0 on success, -1 if b is zero. Result stored in *result. */
int divide(int a, int b, int *result) {
    if (b == 0) {
        return -1;
    }
    *result = a / b;
    return 0;
}