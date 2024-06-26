#include <stdio.h>

void printPattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for (int k = 1; k <= i; k++) {
            printf(" 1 %d ",  k);
        }

        printf("\n");
    }
}

int main() {
    int n = 4; 
    printPattern(n);
    return 0;
}

