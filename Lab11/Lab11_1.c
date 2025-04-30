// Suthang Sukrueangkun
// 67070503477

#include <stdio.h>

void bubbleSort(int arr[], int size);

int main(void) {
    int size;
    int arr[999];

    scanf(" %d", &size);
    for (int i = 0; i < size; i++) scanf(" %d", &arr[i]);

    bubbleSort(arr, size);

    printf("--Sorted array--\n");

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void bubbleSort(int arr[], int size) {
    int i, j, k, tmp;
    
    for (i = 0; i < size - 1; i++) {
        printf("--%d iteration--\n", i + 1);
        for (j = 1; j < size - i; j++) {
            if (arr[j] < arr[j - 1]) {
                // swap
                printf("Swap: %d & %d\n", arr[j - 1], arr[j]);
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
        for (k = 0; k < size; k++) printf("%d ", arr[k]);
        printf("\n");
    }
}
