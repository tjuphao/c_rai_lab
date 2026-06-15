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
 * 1.3.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Update add() to INT_64 with overflow/
 *         |            |                       | underflow detection and NULL pointer check
 */

#include <stdio.h>
#include "hello.h"

/* TODO - Review: REQ-2604091431 in Requirements.csv is incomplete ("The subtraction operation shall accept only").
 * Verify the acceptance condition and update this implementation accordingly. */

#if 0
void say_hello(void) {
    printf("Hello, World!\n");
}
#endif

/* AI-GENERATED: Review required before integration */
/**
 * @brief Adds two 64-bit integers with overflow detection.
 * @details Adds a and b and stores the result via resultPtr.
 *          Checks for NULL pointer and integer overflow/underflow before performing
 *          the operation. Implements: REQ-2604091434 (integer operands),
 *          REQ-2604091435 (64-bit support), REQ-2604091436 (two operands).
 * @param[in]  a         - First addend.
 * @param[in]  b         - Second addend.
 * @param[out] resultPtr - Pointer to store the result of a plus b.
 * @return 0 on success, -1 if resultPtr is NULL or overflow/underflow would occur.
 */
int add(INT_64 a, INT_64 b, INT_64 *resultPtr)
{
    int returnVal;

    if (resultPtr == NULL)
    {
        returnVal = -1;
    }
    else if ((b > 0) && (a > (INT64_MAX - b)))
    {
        /* Overflow: a + b would exceed INT64_MAX. */
        returnVal = -1;
    }
    else if ((b < 0) && (a < (INT64_MIN - b)))
    {
        /* Underflow: a + b would go below INT64_MIN. */
        returnVal = -1;
    }
    else
    {
        *resultPtr = a + b;
        returnVal = 0;
    }

    return (returnVal);
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
 *          the operation. Implements: REQ-2604091429 (integer operands),
 *          REQ-2604091430 (64-bit support), REQ-2604091432 (two operands).
 *          TODO - Review: REQ-2604091431 is incomplete in Requirements.csv. Verify and update.
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
