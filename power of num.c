#include <stdio.h>

int power(int base, int exp) {
    if (exp == 0)
        return 1;
    return base * power(base, exp - 1);
}

int main() {
    int base = 2, exp = 3;
    printf("%d^%d = %d", base, exp, power(base, exp));
    return 0;
}

