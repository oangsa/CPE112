#include <stdio.h>
#include <stdlib.h>

// Counting Sort
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = arr[0];
    int* map;
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    size_t i, j, k;

    // Find the largest elements in array
    for (i = 0; i < arrSize; i++) {
        if (arr[i] > size) size = arr[i];
    }
    size++;

    map = (int*) calloc(size, sizeof(int));

    for (i = 0; i < arrSize; i++) {
        map[arr[i]]++;
    }

    for (i = 0; i < size; i++) {
        for(j = 0; j < map[i]; j++) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
