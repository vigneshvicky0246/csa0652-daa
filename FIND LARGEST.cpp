#include <stdio.h>

int findLargest(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int max_of_rest = findLargest(arr + 1, n - 1);
    return (arr[0] > max_of_rest) ? arr[0] : max_of_rest;
}

int main() {
    int arr[] = {3, 5, 2, 9, 1};
    printf("Largest element is %d\n", findLargest(arr, 5));
    return 0;
}
-
