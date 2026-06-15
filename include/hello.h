/**
 * @file hello.h
 * @brief Public interface for hello module (say_hello, add, divide, subtract).
 *
 * Revision History:
 * Version | Date       | Author                | Description
 * --------|------------|-----------------------|--------------------------------------
 * 1.0.0   | 2026-04-09 | tjuphao               | Initial declarations: say_hello, add
 * 1.1.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add divide() declaration
 * 1.2.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add INT_64 typedef and subtract()
 *         |            |                       | declaration with overflow detection
 * 1.3.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Update add() to INT_64 signature
 */

#ifndef HELLO_H
#define HELLO_H

#include <stdint.h>

typedef int64_t INT_64;
typedef double DOUBLE;

void say_hello(void);
int add(INT_64 a, INT_64 b, INT_64 *resultPtr);
int divide(int a, int b, int *resultPtr);
int subtract(INT_64 a, INT_64 b, INT_64 *resultPtr);

#endif