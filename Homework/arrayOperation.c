//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>

void insertElem(int* arr, int pos, int value, int* curSize);
void deleteElem(int* arr, int pos, int* curSize);
void displayArr(int* arr, int* curSize);

int main(void) {
    // Construct an array using malloc
    int curSize = 7;
    int* arr = (int*) malloc(curSize * sizeof(int));

    // Just construct the initial array... nothing special, right?
    for (int i = 1; i <= curSize; i++) {
        arr[i-1] = i * 11;
    }

    printf("Original array:\n");
    displayArr(arr, &curSize);

    printf("Insert 50 at the 4th index.\n");
    insertElem(arr, 4, 50, &curSize);
    displayArr(arr, &curSize);

    printf("Delete element at the 6th index.\n");
    deleteElem(arr, 6, &curSize);
    displayArr(arr, &curSize);

    free(arr);
    return 0;
}

// Just utility function to make the code readable.
void displayArr(int* arr, int* curSize) {
    for (int i = 0; i < *curSize; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insertElem(int* arr, int pos, int value, int* curSize) {
    // Resize an array....
    arr = (int*) realloc(arr, ++(*curSize) * sizeof(int));

    // Right shift elements in array
    for (int i = (*curSize)-1; i > pos; i--) {
        arr[i] = arr[i-1];
    }

    arr[pos] = value;
}

void deleteElem(int* arr, int pos, int* curSize) {

    // Shift the value to the left start from the expected position (Position that we want to delete).
    // I use size-1 here to prevent our beloved "Sagmentation fault".... if it's happen
    for (int i = pos; i < (*curSize) - 1; i++) {
        arr[i] = arr[i+1];
    }

    // Shrink the array!!!
    arr = (int*) realloc(arr, --(*curSize) * sizeof(int));
}

/*
Algorithm:
Insertion:
    Initial Data:
        size: curSize = 7;
        value to insert: n = 50;
        position: pos = 4;
        array: arr;
        counter: ctr = 1;

    Steps:
        [1st step: Initialize an array]:
            1. malloc an integer array to sizeof "curSize"
            2. while ctr < curSize do step 3, 4
            3. Set an array at index of ctr-1 to ctr*11 ==> arr[ctr-1] = ctr*11;
            4. Increase the value of ctr by 1

            // Current array = {11, 22, 33, 44, 55, 66, 77}

        [2nd step: Resize an array]:
            1. Increase the value of curSize by 1 and set value of "ctr" to the value of "curSize" -1
            2. realloc the array to the size of "curSize"

        [3rd step: Shift the value of the array]
            1. Shift the array start from the last element of the array

            // Current array = {11, 22, 33, 44, 55, 66, 77, 0}
            // Current "curSize" = 8

            while ctr > pos do [Action]
            [Action]:
                At ctr == 7
                    set array at the 7th index to the value of the array of the 6th index ==> arr[7] = arr[7-1]
                    // The array should be {11, 22, 33, 44, 55, 66, 77, 77}

                At ctr == 6
                    set array at the 6th index to the value of the array of the 5th index ==> arr[6] = arr[6-1]
                    // The array should be {11, 22, 33, 44, 55, 66, 66, 77}

                At ctr == 5
                    set array at the 5th index to the value of the array of the 4th index ==> arr[5] = arr[5-1]
                    // The array should be {11, 22, 33, 44, 55, 55, 66, 77}

                Decrease the value of "ctr" by 1

        [4th step: Set the value of the array at the position we want.]
            1. Set the value of the array at the "pos" index to the value of "n" ==> arr[pos] = n

        // The array should be = {11, 22, 33, 44, 50, 55, 66, 77} :)

Deletion:

    **Suppose this action executed after the insertion**

    Initial Data:
        size: curSize = 8;
        position: pos = 6;
        array: arr;
        counter: ctr = 1;

    Steps:
        [1st step: Shift the value of the array to the left]
            1. Shift the array start from the "pos" index to the last element of the array
            2. set the value of "ctr" to the value of "pos" ==> ctr = pos

            // Current array = {11, 22, 33, 44, 50, 55, 66, 77}

            while ctr < curSize - 1 do [Action]
            [Action]:
                1. At ctr == pos
                    set array at the "pos" index to the value of the array of the "pos" + 1 th index ==> arr[6] = arr[7+1]
                    // The array should be {11, 22, 33, 44, 50, 55, 77, 77}

                2. Increase the value of "ctr" by 1

        [2nd step: Resize an array]:
            1. Decrease the value of curSize by 1
            2. realloc the array to the size of "curSize"

        // The final array should be = {11, 22, 33, 44, 50, 55, 77} :)
        // I'm trying my best to explain this algorithm.
*/
