#include <stdio.h>

void bubbleSort(int arr[], int size);

int main() {
    int arr[] = {99, 3, 15, 26, 32, 41, 55, 1, 100};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, size);

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void bubbleSort(int arr[], int size) {
    int ctr = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size - i; j++) {
            if (arr[j-1] > arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;

                ctr++;
            }
        }
    }

    printf("Swap count: %d\n", ctr);
}
