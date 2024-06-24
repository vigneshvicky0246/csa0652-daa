#include <stdio.h>

int main() {
    int n = 5;
    int factorial = 1;
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    printf("The factorial of %d is %llu\n", n, factorial);


}
