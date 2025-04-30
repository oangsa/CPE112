// Suthang Sukrueangkun
// 67070503477

#include <stdio.h>

void selectionSort(int arr[], int size);

int main(void) {
    int size;
    int arr[999];

    scanf(" %d", &size);
    for (int i = 0; i < size; i++) scanf(" %d", &arr[i]);

    selectionSort(arr, size);

    printf("--Sorted array--\n");

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void selectionSort(int arr[], int size) {
    int i, j, k, tmp, minIndex;

    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        printf("--%d iteration--\n", i + 1);

        for (j = i + 1; j < size; j++) {
            if (arr[minIndex] > arr[j]) minIndex = j;
        }

        // swap
        printf("Swap: %d & %d\n", arr[i], arr[minIndex]);
        tmp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = tmp;
        for (int i = 0; i < size; i++) printf("%d ", arr[i]);
        printf("\n");
    }
}
