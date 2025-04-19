#include <stdio.h>

void QuickSort(int arr[], int size, int low, int high);

int main(void) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorted.\n");

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);

    QuickSort(arr, size, 0, -1);
    printf("\n Array after sorted.\n");

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void QuickSort(int arr[], int size, int low, int high) {
    if (high == -1) high = size - 1;

    if (low  < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        QuickSort(arr, size, low, i);
        // Add +2 because we wanna skip the pivot that is alreay sorted
        QuickSort(arr, size, i + 2, high);
    }
}
