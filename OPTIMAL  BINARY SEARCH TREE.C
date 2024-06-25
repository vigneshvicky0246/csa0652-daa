#include <stdio.h>
#include <limits.h>
int matrixChainOrder(int p[], int n) {
    int m[n][n];  
    int i, j, k, L, q;
    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int n,i;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int p[n + 1];
    printf("Enter the dimensions of the matrices:\n");
    for (i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    int cost = matrixChainOrder(p, n + 1);
    printf("The minimum number of multiplications is %d\n", cost);

    return 0;
}
