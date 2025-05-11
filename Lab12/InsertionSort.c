#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 100000

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void InsertionSort(int arr[], int size) {
    size_t i, j;
    int temp, curV;
    for (i = 0; i < size - 1; i++) {
        curV = arr[i];
        for (j = 0; j < i; j++) {
            if (curV < arr[j]) {
                // Shifting Number for insertion
                // Shift all elements starting from the last element to the current index
                for (int k = i; k > j; k--) {
                    arr[k] = arr[k-1];
                }
                arr[j] = curV;
                break;
            }
        }
    }
}

void readfile(const char *fileName,const char *name){
    FILE *file = fopen(fileName, "r");
    if (file == NULL){
        printf("Failed to open file.\n");
    }

    int n = MAX_SIZE;
    int arr[n];

    for (int i = 0; i < MAX_SIZE; i++){
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    clock_t start, end;
    printf("Start sorting.....");
    start = clock();

    InsertionSort(arr, n);

    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    //printArray(arr, n);
    printf("\nInsertion Sort Execution time (%s): %.6f seconds\n",fileName, time_taken);
}

int main() {
    readfile("AscendingCase.txt","Ascending case: ");
    readfile("RandomizedCase.txt","Randomized case: ");
    readfile("DescendingCase.txt","Descending case: ");

    return 0;
}
