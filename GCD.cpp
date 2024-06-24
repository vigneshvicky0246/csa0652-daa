#include <stdio.h>

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int main() {
    printf("GCD of 48 and 18 is %d\n", gcd(48, 18));
    return 0;
}

