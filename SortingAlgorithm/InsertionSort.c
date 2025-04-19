#include <stdio.h>

void InsertionSort(int arr[], int size);

int main(void) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorted.\n");

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);

    InsertionSort(arr, size);
    printf("\n Array after sorted.\n");

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void InsertionSort(int arr[], int size) {
    size_t i, j;
    int temp, curV;
    for (i = 0; i < size - 1; i++) {
        curV = arr[i];
        for (j = 0; j < i; j++) {
            if (curV < arr[j]) {
                // Shifting Number for insertion
                // Shift all elements starting from the last element to the current index
                for (int k = i; k > j; k--) {
                    arr[k] = arr[k-1];
                }
                arr[j] = curV;
                break;
            }
        }
    }
}
