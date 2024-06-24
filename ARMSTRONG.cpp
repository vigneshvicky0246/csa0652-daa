#include <stdio.h>
#include <math.h>

int numDigits(int num) {
    return (num == 0) ? 0 : 1 + numDigits(num / 10);
}

int isArmstrong(int num, int power) {
    return (num == 0) ? 0 :
	 pow(num % 10, power) + isArmstrong(num / 10, power);
}

int main() {
    int num = 153;
    int power = numDigits(num);
    printf("%d is %s\n", num, (num == isArmstrong(num, power)) ? "an Armstrong number" : "not an Armstrong number");
    return 0;
}

