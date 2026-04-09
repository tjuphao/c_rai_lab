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
 */

#include "CppUTest/TestHarness.h"

extern "C" {
#include "hello.h"
}

TEST_GROUP(HelloGroup) {};

// add()
TEST(HelloGroup, AddPositiveNumbers) {
    CHECK_EQUAL(5, add(2, 3));
}

TEST(HelloGroup, AddNegativeNumbers) {
    CHECK_EQUAL(-1, add(-3, 2));
}

// divide()
TEST(HelloGroup, DivideSuccess) {
    int result = 0;
    CHECK_EQUAL(0, divide(10, 2, &result));
    CHECK_EQUAL(5, result);
}

TEST(HelloGroup, DivideByZeroReturnsError) {
    int result = 0;
    CHECK_EQUAL(-1, divide(10, 0, &result));
}

TEST(HelloGroup, DivideNullPtrReturnsError) {
    CHECK_EQUAL(-1, divide(10, 2, NULL));
}

// subtract()
TEST(HelloGroup, SubtractSuccess) {
    INT_64 result = 0;
    CHECK_EQUAL(0, subtract(10, 3, &result));
    CHECK_EQUAL(7, result);
}

TEST(HelloGroup, SubtractNegativeResult) {
    INT_64 result = 0;
    CHECK_EQUAL(0, subtract(3, 10, &result));
    CHECK_EQUAL(-7, result);
}

TEST(HelloGroup, SubtractNullPtrReturnsError) {
    CHECK_EQUAL(-1, subtract(10, 3, NULL));
}

TEST(HelloGroup, SubtractUnderflowReturnsError) {
    INT_64 result = 0;
    CHECK_EQUAL(-1, subtract(INT64_MIN, 1, &result));
}

TEST(HelloGroup, SubtractOverflowReturnsError) {
    INT_64 result = 0;
    CHECK_EQUAL(-1, subtract(INT64_MAX, -1, &result));
}

TEST(HelloGroup, SubtractNegativeSubtrahendNoOverflow) {
    INT_64 result = 0;
    CHECK_EQUAL(0, subtract(5, -3, &result));
    CHECK_EQUAL(8, result);
}
