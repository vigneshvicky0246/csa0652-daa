#include <stdio.h>

void findMaxMin(int arr[], int low, int high, int *min, int *max) {
    if (low == high) {
        *min = *max = arr[low];
    } else if (high == low + 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
    } else {
        int mid = (low + high) / 2;
        int min1, max1, min2, max2;

        findMaxMin(arr, low, mid, &min1, &max1);
        findMaxMin(arr, mid + 1, high, &min2, &max2);

        *min = (min1 < min2) ? min1 : min2;
        *max = (max1 > max2) ? max1 : max2;
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMaxMin(arr, 0, size - 1, &min, &max);

    printf("Minimum Value: %d\n", min);
    printf("Maximum Value: %d\n", max);

    return 0;
}

