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
 */

#ifndef HELLO_H
#define HELLO_H

#include <stdint.h>

typedef int64_t INT_64;

void say_hello(void);
int add(int a, int b);
int divide(int a, int b, int *resultPtr);
int subtract(INT_64 a, INT_64 b, INT_64 *resultPtr);

#endif