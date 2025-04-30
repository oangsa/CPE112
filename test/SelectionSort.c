#include <stdio.h>

void selectionSort(int arr[], int size);

int main(void) {
    int arr[] = {99, 3, 15, 26, 32, 41, 55, 1, 100};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, size);

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void selectionSort(int arr[], int size) {
    int i, j, k, idx;

    for (i = 0; i < size - 1; i++) {
        idx = i;

        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[idx]) idx = j;
        }

        k = arr[i];
        arr[i] = arr[idx];
        arr[idx] = k;
    }
}
