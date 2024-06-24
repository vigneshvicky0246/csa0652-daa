#include <stdio.h>
#include <stdlib.h>

int add(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        int newSize = n / 2;
        int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
        int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
        int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
        int M1[newSize][newSize], M2[newSize][newSize], M3[newSize][newSize], M4[newSize][newSize];
        int M5[newSize][newSize], M6[newSize][newSize], M7[newSize][newSize];
        int temp1[newSize][newSize], temp2[newSize][newSize];

        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + newSize];
                A21[i][j] = A[i + newSize][j];
                A22[i][j] = A[i + newSize][j + newSize];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + newSize];
                B21[i][j] = B[i + newSize][j];
                B22[i][j] = B[i + newSize][j + newSize];
            }
        }

        add(newSize, A11, A22, temp1);
        add(newSize, B11, B22, temp2);
        strassen(newSize, temp1, temp2, M1);

        add(newSize, A21, A22, temp1);
        strassen(newSize, temp1, B11, M2);

        subtract(newSize, B12, B22, temp1);
        strassen(newSize, A11, temp1, M3);

        subtract(newSize, B21, B11, temp1);
        strassen(newSize, A22, temp1, M4);

        add(newSize, A11, A12, temp1);
        strassen(newSize, temp1, B22, M5);

        subtract(newSize, A21, A11, temp1);
        add(newSize, B11, B12, temp2);
        strassen(newSize, temp1, temp2, M6);

        subtract(newSize, A12, A22, temp1);
        add(newSize, B21, B22, temp2);
        strassen(newSize, temp1, temp2, M7);

        add(newSize, M1, M4, temp1);
        subtract(newSize, temp1, M5, temp2);
        add(newSize, temp2, M7, C11);

        add(newSize, M3, M5, C12);
        add(newSize, M2, M4, C21);

        add(newSize, M1, M3, temp1);
        subtract(newSize, temp1, M2, temp2);
        add(newSize, temp2, M6, C22);

        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                C[i][j] = C11[i][j];
                C[i][j + newSize] = C12[i][j];
                C[i + newSize][j] = C21[i][j];
                C[i + newSize][j + newSize] = C22[i][j];
            }
        }
    }
}

int main() {
    int n = 2;
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];

    strassen(n, A, B, C);

    printf("Result of Strassen's Matrix Multiplication:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

