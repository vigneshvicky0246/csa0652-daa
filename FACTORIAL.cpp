#include <stdio.h>

int factorial(int n) {
    return (n == 0) ? 1 : n * factorial(n - 1);
}

int main() {
    printf("Factorial of 5 is %d\n", factorial(5));
    return 0;
}

