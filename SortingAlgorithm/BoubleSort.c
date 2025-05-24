#include <stdio.h>

void BubbleSort(int arr[], int size);

int main(void) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Array before sorted.\n");
    
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    
    BubbleSort(arr, size);
    printf("\n Array after sorted.\n");
    
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void BubbleSort(int arr[], int size) {
    size_t i, j;
    int temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] >= arr[j+1]) {
                // Swap two numbers
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
