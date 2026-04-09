/**
 * @file hello.c
 * @brief Implementation of hello module (say_hello, add, divide, subtract).
 *
 * Revision History:
 * Version | Date       | Author                | Description
 * --------|------------|-----------------------|--------------------------------------
 * 1.0.0   | 2026-04-09 | tjuphao               | Initial implementation: say_hello, add
 * 1.1.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add divide() with NULL and div-by-zero
 *         |            |                       | checks
 * 1.2.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add subtract() with overflow/underflow
 *         |            |                       | detection and NULL pointer check
 */

#include <stdio.h>
#include "hello.h"

/* TODO - Review: REQ-5 in Requirements.csv is incomplete ("The subtraction operation shall accept only").
 * Verify the acceptance condition and update this implementation accordingly. */

#if 0
void say_hello(void) {
    printf("Hello, World!\n");
}
#endif

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
 * @brief Subtracts two 64-bit integers with overflow detection.
 * @details Subtracts b from a and stores the result via resultPtr.
 *          Checks for NULL pointer and integer overflow/underflow before performing
 *          the operation. Implements: REQ-3 (integer operands), REQ-4 (64-bit support),
 *          REQ-6 (two operands).
 *          TODO - Review: REQ-5 is incomplete in Requirements.csv. Verify and update.
 * @param[in]  a         - Minuend.
 * @param[in]  b         - Subtrahend.
 * @param[out] resultPtr - Pointer to store the result of a minus b.
 * @return 0 on success, -1 if resultPtr is NULL or overflow/underflow would occur.
 */
int subtract(INT_64 a, INT_64 b, INT_64 *resultPtr)
{
    int returnVal;

    if (resultPtr == NULL)
    {
        returnVal = -1;
    }
    else if ((b > 0) && (a < (INT64_MIN + b)))
    {
        /* Underflow: a - b would go below INT64_MIN. */
        returnVal = -1;
    }
    else if ((b < 0) && (a > (INT64_MAX + b)))
    {
        /* Overflow: a - b would exceed INT64_MAX. */
        returnVal = -1;
    }
    else
    {
        *resultPtr = a - b;
        returnVal = 0;
    }

    return (returnVal);
}
