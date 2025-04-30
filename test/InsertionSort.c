#include <stdio.h>

void insertionSort(int arr[], int size);

int main() {
    int arr[] = {99, 3, 15, 26, 32, 41, 55, 1, 100};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, size);

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void insertionSort(int arr[], int size) {
    int i, j, k, tmp;
    for (i = 0; i < size; i++) {
        tmp = arr[i];

        for (j = 0; j < i; j++) {
            if (tmp < arr[j]) {
                for (k = i; k > j; k--) {
                    arr[k] = arr[k-1];
                }

                arr[j] = tmp;
                break;
            }
        }
    }
}
