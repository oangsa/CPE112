//Suthang Sukrueangkun
//67070503477

#include<stdio.h>

void sortAscending(int arr[], int size);

int main(void) {

    int size;
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    sortAscending(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void sortAscending(int arr[], int size){
    for(int i = 0; i < size; i++) {
        for(int j = 1; j < size - i; j++) {
            if (arr[j] <= arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}
