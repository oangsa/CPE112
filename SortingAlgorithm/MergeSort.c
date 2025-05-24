#include <stdio.h>

void MergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorted.\n");

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);

    MergeSort(arr, 0, size - 1);
    printf("\n Array after sorted.\n");

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void MergeSort(int arr[], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);

}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) M[i] = arr[mid + 1 + i];

    size_t i, j, k;
    i = j = 0;
    k = left;

    while(i < n1 && j < n2) {
        if (L[i] > M[j]) {
            arr[k] = M[j];
            j++;
        }
        else {
            arr[k] = L[i];
            i++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }



}
