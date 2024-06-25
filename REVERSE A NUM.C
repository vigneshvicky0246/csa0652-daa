#include <stdio.h>

int reverseNumber(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Reversed Number: %d\n", reverseNumber(num));
    return 0;
}

