
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 100000

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    
    int tmp = arr[i + 1];
    arr[i+1] = arr[high];
    arr[high] = tmp;
    return i + 1;
}

// The QuickSort function implementation
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    char fileName[3][999] = {"AscendingCase.txt", "RandomizedCase.txt" ,"DescendingCase.txt"};

    for (int i = 0; i < 3; i++) {

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

        quickSort(arr, 0, n - 1); // Change Sorting Algorithm right here

        end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        // clock should end right here, before displaying the entire process

        // printArray(arr, n);
        printf("\nQuick Sort Execution time (%s): %.6f seconds\n",fileName[i], time_taken);
    }
    return 0;

}
