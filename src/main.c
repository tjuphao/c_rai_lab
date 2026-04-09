#include <stdio.h>
#include "hello.h"

int main() {
    int a = 5;
    int b = 10;
    int result = add(a, b);
    int resultDiv;

    if (divide(a, b, &resultDiv) == 0)
    {
        printf("The result of %d / %d is %d\n", a, b, resultDiv);
    }
    else
    {
        printf("Error: Division by zero or null pointer.\n");
    }

    printf("The result of %d + %d is %d\n", a, b, result);
    say_hello();

    return 0;
}