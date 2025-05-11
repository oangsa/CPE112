#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 100000

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectiontionSort(int arr[], int size){
    for (int i = 0 ; i < size ; i++){
        int min_index = i ;
        for (int j = i+1 ; j < size ; j++){
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}

/*int main() {
    FILE *file = fopen("AscendingCase.txt", "r"); // any .txt file that you want to test
    if (file == NULL){
        printf("Failed to open file.\n");
        return 1;
    }

    int n = MAX_SIZE;
    int arr[n];

    // file reading process
    for (int i = 0; i < MAX_SIZE; i++){
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    // clock should start right here, without reading file and displaying process
    clock_t start, end;
    printf("Start sorting.....");
    start = clock();

    SelectiontionSort(arr, n); // Change Sorting Algorithm right here

    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    // clock should end right here, before displaying the entire process
    printf("Ascending case: ");
    printArray(arr, n);
    printf("\nExecution time: %.6f seconds\n", time_taken);

    return 0;
}*/
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

    SelectiontionSort(arr, n);

    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    //printArray(arr, n);
    printf("\nSelection Sort Execution time (%s): %.6f seconds\n",fileName, time_taken);
}

int main() {
    readfile("AscendingCase.txt","Ascending case: ");
    readfile("RandomizedCase.txt","Randomized case: ");
    readfile("DescendingCase.txt","Descending case: ");
    return 0;
}
