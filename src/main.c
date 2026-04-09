#include <stdio.h>
#include "hello.h"

int main() {
    INT_64 a = 5;
    INT_64 b = 10;
    INT_64 resultAdd = 0;
    DOUBLE resultDiv = 0.0;

    printf("======= Responsible AI Demonstration ===========================\n");
    printf("Performing subtraction, addition and division on a=%lld and b=%lld\n", (long long)a, (long long)b);
    printf("================================================================\n");

    if (subtract(a, b, &resultAdd) == 0)
    {
        printf("The result of %lld - %lld is %lld\n", (long long)a, (long long)b, (long long)resultAdd);
    }
    else
    {
        printf("Error: Subtraction overflow/underflow or null pointer.\n");
    }
    
    if (add(a, b, &resultAdd) == 0)
    {
        printf("The result of %lld + %lld is %lld\n", (long long)a, (long long)b, (long long)resultAdd);
    }
    else
    {
        printf("Error: Addition overflow/underflow or null pointer.\n");
    }

    if (divide(a, b, &resultDiv) == 0)
    {
        /* REQ-2604091921: display two decimal places if remainder exists.
         * REQ-2604091922: display no decimal places if result is exact. */
        if (resultDiv == (DOUBLE)(INT_64)resultDiv)
        {
            printf("The result of %lld / %lld is %lld\n",
                   (long long)a, (long long)b, (long long)(INT_64)resultDiv);
        }
        else
        {
            printf("The result of %lld / %lld is %.2f\n",
                   (long long)a, (long long)b, resultDiv);
        }
    }
    else
    {
        printf("Error: Division by zero or null pointer.\n");
    }

    return 0;
}