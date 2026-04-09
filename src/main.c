#include <stdio.h>
#include "hello.h"

int main() {
    INT_64 a = 5;
    INT_64 b = 10;
    INT_64 resultAdd = 0;
    int resultDiv;

    if (add(a, b, &resultAdd) == 0)
    {
        printf("The result of %lld + %lld is %lld\n", (long long)a, (long long)b, (long long)resultAdd);
    }
    else
    {
        printf("Error: Addition overflow/underflow or null pointer.\n");
    }

    if (divide((int)a, (int)b, &resultDiv) == 0)
    {
        printf("The result of %lld / %lld is %d\n", (long long)a, (long long)b, resultDiv);
    }
    else
    {
        printf("Error: Division by zero or null pointer.\n");
    }

    say_hello();

    return 0;
}