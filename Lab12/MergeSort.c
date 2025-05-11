#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 100000

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void Merge (int arr[], int left, int mid , int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
        }

    }
    while (i < n1){
        arr[k++] = L[i++];
    }
    while (j < n2){
        arr[k++] = R[j++];
    }
}

void AnySortingAlgo(int arr[], int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        AnySortingAlgo(arr, left, mid);
        AnySortingAlgo(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

int main() {
    char fileName[3][999] = {"AscendingCase.txt", "RandomizedCase.txt" ,"DescendingCase.txt"};
    for (int i =0; i < 3; i++) {
        FILE *file = fopen(fileName[i], "r"); // any .txt file that you want to test
        if (file == NULL)
        {
            printf("Failed to open file.\n");
            return 1;
        }

        int n = MAX_SIZE;
        int arr[n];

        // file reading process
        for (int i = 0; i < MAX_SIZE; i++)
        {
            fscanf(file, "%d", &arr[i]);
        }

        fclose(file);

        // clock should start right here, without reading file and displaying process
        clock_t start, end;
        printf("Start sorting.....");
        start = clock();

        AnySortingAlgo(arr, 0, MAX_SIZE-1); // Change Sorting Algorithm right here

        end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        // clock should end right here, before displaying the entire process

        printf("\nMerge Sort Execution time (%s): %.6f seconds\n",fileName[i], time_taken);
    }

    return 0;
}
