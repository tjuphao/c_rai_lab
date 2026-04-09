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
