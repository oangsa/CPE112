#include <stdio.h>

void RadixSort(int arr[], int size);
void CounterSort(int arr[], int size, int max, int place);
int findMax(int arr[], int size);

int main(void) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorted.\n");

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    RadixSort(arr, size);
    printf("Array after sorted.\n");

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

int findMax(int arr[], int size) {
    int max = arr[0];
    size_t i;

    for (i = 0; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }

    return max;
}

void RadixSort(int arr[], int size) {
    int mx = findMax(arr, size);
    // printf("mx: %d\n", mx);
    size_t i;

    for (i = 1; (mx / i) > 0; i *= 10) {
        // printf("%d ", i);
        CounterSort(arr, size, mx, i);
    }
}

void CounterSort(int arr[], int size, int max, int place) {
    int a[size];
    int ctr[10] = {0};
    int index;
    int i;

    for (i = 0; i < size; i++) {
        index = (arr[i] / place) % 10;
        ctr[index]++;
    }

    for (i = 1; i < 10; i++) {
        ctr[i] += ctr[i - 1];
    }

    for (i = size - 1; i >= 0; i--) {
        index = (arr[i] / place) % 10;
        a[ctr[index] - 1] = arr[i];
        ctr[index]--;
    }

    for(i = 0; i < size; i++) {
        arr[i] = a[i];
    }
}
