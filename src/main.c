#include <stdio.h>
#include "hello.h"

int main() {
    int a = 5;
    int b = 10;
    int result = add(a, b);

    printf("The result of %d + %d is %d\n", a, b, result);
    say_hello();

    return 0;
}