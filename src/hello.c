#include <stdio.h>
#include "hello.h"

/* TODO - Review: REQ-5 in Requirements.csv is incomplete ("The subtraction operation shall accept only").
 * Verify the acceptance condition and update this implementation accordingly. */

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

/* AI-GENERATED: Review required before integration */
/**
 * @brief Subtracts two 64-bit integers.
 * @details Subtracts b from a and returns the result.
 *          Implements: REQ-3 (integer operands), REQ-4 (64-bit support), REQ-6 (two operands).
 * @param[in] a - Minuend.
 * @param[in] b - Subtrahend.
 * @return Result of a minus b.
 */
INT_64 subtract(INT_64 a, INT_64 b)
{
    return (a - b);
}
