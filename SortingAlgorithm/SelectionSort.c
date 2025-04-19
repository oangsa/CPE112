#include <stdio.h>

void SelectionSort(int arr[], int size);

int main(void) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Array before sorted.\n");
    
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    
    SelectionSort(arr, size);
    printf("\n Array after sorted.\n");
    
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void SelectionSort(int arr[], int size) {
    size_t i, j;
    int temp;
    for (i = 0; i < size; i++) {
        temp = i;
        for (j = i; j < size; j++) {
            if (arr[temp] > arr[j]) temp = j;
        }
        // Swap
        int t = arr[temp];
        arr[temp] = arr[i];
        arr[i] = t;
    }
}
