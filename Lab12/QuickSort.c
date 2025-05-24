
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 100000

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int medianOfThree(int arr[], int f, int e) {
    int mid = ((e - f) / 2) + 1;
    int a = arr[f];
    int b = arr[mid];
    int c = arr[e];

    // returns the index
    if ((a > b) ^ (a > c))
        return f;
    else if ((b < a) ^ (b < c))
        return mid;
    else
        return e;
}

void quickSort(int arr[], int size, int low, int high) {
    if (high == -1) high = size - 1;
    if (low >= high) return;

    int pivotIndex = medianOfThree(arr, low, high);
    int pivot = arr[pivotIndex];

    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[high];
    arr[high] = temp;

    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    quickSort(arr, size, low, i - 1);
    quickSort(arr, size, i + 1, high);
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
        int arr[MAX_SIZE];

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

        quickSort(arr, n, 0, n - 1); // Change Sorting Algorithm right here

        end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        // clock should end right here, before displaying the entire process

        // printArray(arr, n);
        printf("\nQuick Sort Execution time (%s): %.6f seconds\n",fileName[i], time_taken);
    }
    return 0;

}
