#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(int n) {
    bool primes[n + 1];
    for (int i = 0; i <= n; i++) {
        primes[i] = true;
    }

    for (int p = 2; p * p <= n; p++) {
        if (primes[p]) {
            for (int i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }

    printf("Prime Numbers: ");
    for (int p = 2; p <= n; p++) {
        if (primes[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");
}

int main() {
    int n = 50;
    sieveOfEratosthenes(n);
    return 0;
}

