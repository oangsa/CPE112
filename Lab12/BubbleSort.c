#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 100000

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void AnySortingAlgo(int arr[], int n)
{
    for (int i = 0 ; i<n-1 ; i++){
        for (int j = 0 ;j < n-i-1 ; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
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

        AnySortingAlgo(arr, n); // Change Sorting Algorithm right here

        end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        // clock should end right here, before displaying the entire process

        printf("\nBubble Sort Execution time (%s): %.6f seconds\n",fileName[i], time_taken);

    }
    return 0;
}
