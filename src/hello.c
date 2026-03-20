#include <stdio.h>
#include "hello.h"

void say_hello(void) {
    printf("Hello, World!\n");
}

int add(int a, int b) {
    return a + b;
}

/* AI-GENERATED: Review required before integration */
/**
 * @brief Divides two integers.
 * @details Performs integer division of a by b. Returns error if b is zero.
 * @param[in] a - Dividend.
 * @param[in] b - Divisor.
 * @param[out] resultPtr - Pointer to store the division result.
 * @return 0 on success, -1 if b is zero.
 */
int divide(int a, int b, int *resultPtr)
{
    int returnVal;

    if ((b == 0) || (resultPtr == NULL))
    {
        returnVal = -1;
    }
    else
    {
        *resultPtr = a / b;
        returnVal = 0;
    }

    return (returnVal);
}
