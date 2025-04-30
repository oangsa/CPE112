#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int arr[] = {99, 3, 15, 26, 32, 41, 55, 1, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int mx = arr[0];

    for (int i = 0; i < size; i++) if (arr[i] > mx) mx = arr[i];

    int* m = (int*) calloc(mx, sizeof(int));

    for (int i = 0; i < size; i++) {
        m[arr[i]]++;
    }

    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < m[i]; j++) {
            printf("%d ", i);
        }
    }
    printf("\n");


    return 0;
}
