#include <stdio.h>

int isPrime(int n, int i) {
    if (n <= 2)
        return n == 2 ? 1 : 0;
    if (n % i == 0)
        return 0;
    if (i * i > n)
        return 1;
    return isPrime(n, i + 1);
}

int main() {
    int num = 12;
    if (isPrime(num, 2))
        printf("%d is a prime number\n", num);
    else
        printf("%d is not a prime number\n", num);
    return 0;
}

