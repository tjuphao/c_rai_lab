/**
 * @file HelloTest.cpp
 * @brief CppUTest unit tests for hello.c (add, divide, subtract).
 *
 * Revision History:
 * Version | Date       | Author                | Description
 * --------|------------|-----------------------|--------------------------------------
 * 1.0.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Initial tests for add() and divide()
 * 1.1.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add subtract() tests with overflow,
 *         |            |                       | underflow, and NULL pointer checks
 * 1.2.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add SubtractNegativeSubtrahendNoOverflow
 *         |            |                       | to achieve 100% MC/DC branch coverage
 * 1.3.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Update add() tests for INT_64 signature;
 *         |            |                       | add overflow, underflow, NULL pointer checks
 * 1.4.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add unique test ID and input/output
 *         |            |                       | description comments to all test cases
 */

#include "CppUTest/TestHarness.h"

extern "C" {
#include "hello.h"
}

TEST_GROUP(HelloGroup) {};

// add()

/* Test ID: 1775739600
 * Description: Verify add() returns success for two positive integers.
 * Input: a=2, b=3, resultPtr=valid pointer.
 * Expected: return value=0, result=5. */
TEST(HelloGroup, AddPositiveNumbers) {
    INT_64 result = 0;
    CHECK_EQUAL(0, add(2, 3, &result));
    CHECK_EQUAL(5, result);
}

/* Test ID: 1775739601
 * Description: Verify add() returns success when one addend is negative.
 * Input: a=-3, b=2, resultPtr=valid pointer.
 * Expected: return value=0, result=-1. */
TEST(HelloGroup, AddNegativeNumbers) {
    INT_64 result = 0;
    CHECK_EQUAL(0, add(-3, 2, &result));
    CHECK_EQUAL(-1, result);
}

/* Test ID: 1775739602
 * Description: Verify add() returns error when resultPtr is NULL.
 * Input: a=2, b=3, resultPtr=NULL.
 * Expected: return value=-1. */
TEST(HelloGroup, AddNullPtrReturnsError) {
    CHECK_EQUAL(-1, add(2, 3, NULL));
}

/* Test ID: 1775739603
 * Description: Verify add() returns error when result would overflow INT64_MAX.
 * Input: a=INT64_MAX, b=1, resultPtr=valid pointer.
 * Expected: return value=-1. */
TEST(HelloGroup, AddOverflowReturnsError) {
    INT_64 result = 0;
    CHECK_EQUAL(-1, add(INT64_MAX, 1, &result));
}

/* Test ID: 1775739604
 * Description: Verify add() returns error when result would underflow INT64_MIN.
 * Input: a=INT64_MIN, b=-1, resultPtr=valid pointer.
 * Expected: return value=-1. */
TEST(HelloGroup, AddUnderflowReturnsError) {
    INT_64 result = 0;
    CHECK_EQUAL(-1, add(INT64_MIN, -1, &result));
}

/* Test ID: 1775739605
 * Description: Verify add() returns success when negative addend does not cause underflow.
 * Input: a=5, b=-3, resultPtr=valid pointer.
 * Expected: return value=0, result=2. */
TEST(HelloGroup, AddNegativeAddendNoUnderflow) {
    INT_64 result = 0;
    CHECK_EQUAL(0, add(5, -3, &result));
    CHECK_EQUAL(2, result);
}

// divide()

/* Test ID: 1775739606
 * Description: Verify divide() returns success for valid integer division.
 * Input: a=10, b=2, resultPtr=valid pointer.
 * Expected: return value=0, result=5. */
TEST(HelloGroup, DivideSuccess) {
    int result = 0;
    CHECK_EQUAL(0, divide(10, 2, &result));
    CHECK_EQUAL(5, result);
}

/* Test ID: 1775739607
 * Description: Verify divide() returns error when divisor is zero.
 * Input: a=10, b=0, resultPtr=valid pointer.
 * Expected: return value=-1. */
TEST(HelloGroup, DivideByZeroReturnsError) {
    int result = 0;
    CHECK_EQUAL(-1, divide(10, 0, &result));
}

/* Test ID: 1775739608
 * Description: Verify divide() returns error when resultPtr is NULL.
 * Input: a=10, b=2, resultPtr=NULL.
 * Expected: return value=-1. */
TEST(HelloGroup, DivideNullPtrReturnsError) {
    CHECK_EQUAL(-1, divide(10, 2, NULL));
}

// subtract()

/* Test ID: 1775739609
 * Description: Verify subtract() returns success for valid subtraction.
 * Input: a=10, b=3, resultPtr=valid pointer.
 * Expected: return value=0, result=7. */
TEST(HelloGroup, SubtractSuccess) {
    INT_64 result = 0;
    CHECK_EQUAL(0, subtract(10, 3, &result));
    CHECK_EQUAL(7, result);
}

/* Test ID: 1775739610
 * Description: Verify subtract() returns success when result is negative.
 * Input: a=3, b=10, resultPtr=valid pointer.
 * Expected: return value=0, result=-7. */
TEST(HelloGroup, SubtractNegativeResult) {
    INT_64 result = 0;
    CHECK_EQUAL(0, subtract(3, 10, &result));
    CHECK_EQUAL(-7, result);
}

/* Test ID: 1775739611
 * Description: Verify subtract() returns error when resultPtr is NULL.
 * Input: a=10, b=3, resultPtr=NULL.
 * Expected: return value=-1. */
TEST(HelloGroup, SubtractNullPtrReturnsError) {
    CHECK_EQUAL(-1, subtract(10, 3, NULL));
}

/* Test ID: 1775739612
 * Description: Verify subtract() returns error when result would underflow INT64_MIN.
 * Input: a=INT64_MIN, b=1, resultPtr=valid pointer.
 * Expected: return value=-1. */
TEST(HelloGroup, SubtractUnderflowReturnsError) {
    INT_64 result = 0;
    CHECK_EQUAL(-1, subtract(INT64_MIN, 1, &result));
}

/* Test ID: 1775739613
 * Description: Verify subtract() returns error when result would overflow INT64_MAX.
 * Input: a=INT64_MAX, b=-1, resultPtr=valid pointer.
 * Expected: return value=-1. */
TEST(HelloGroup, SubtractOverflowReturnsError) {
    INT_64 result = 0;
    CHECK_EQUAL(-1, subtract(INT64_MAX, -1, &result));
}

/* Test ID: 1775739614
 * Description: Verify subtract() returns success when negative subtrahend does not cause overflow.
 * Input: a=5, b=-3, resultPtr=valid pointer.
 * Expected: return value=0, result=8. */
TEST(HelloGroup, SubtractNegativeSubtrahendNoOverflow) {
    INT_64 result = 0;
    CHECK_EQUAL(0, subtract(5, -3, &result));
    CHECK_EQUAL(8, result);
}
