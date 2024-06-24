#include <stdio.h>

int main() {
    int n = 10;
    int a = 0, b = 1, c;

    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }

    printf("The %dth Fibonacci number is %llu\n", n, b);

}
