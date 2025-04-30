
// Suthang Sukrueangkun
// 67070503477

#include <stdio.h>

void insertionSort(int arr[], int size);

int main(void) {
    int size;
    int arr[999];

    scanf(" %d", &size);
    for (int i = 0; i < size; i++) scanf(" %d", &arr[i]);

    insertionSort(arr, size);

    printf("--Sorted array--\n");

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void insertionSort(int arr[], int size) {
    int i, j, k, tmp;

    for (i = 1; i < size; i++) {
        printf("--%d Pass--\n", i);
        for (j = 0; j < i; j++) {
            tmp = arr[i];
            if (tmp < arr[j]) {
                // Shift numbers
                for (k = i; k > j; k--) {
                    arr[k] = arr[k - 1];
                }

                arr[j] = tmp;
                break;
            }
        }
        printf("%d Pass to index %d\n", tmp, j);
        for (int i = 0; i < size; i++) printf("%d ", arr[i]);
        printf("\n");
    }
}
