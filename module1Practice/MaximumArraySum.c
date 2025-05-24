//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int maxSum(int* arr, int size);

int main(void) {

    int s;

    scanf("%d", &s);

    int* arr = (int*) malloc(sizeof(int) * s);

    for (int i = 0; i < s; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Max: %d\n", maxSum(arr, s));
    free(arr);

    return 0;
}

int maxSum(int* arr, int size) {
    int curSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < size; i++) {
        curSum += arr[i];

        if (curSum > maxSum) maxSum = curSum;
        if (curSum < 0) curSum = 0;
    }

    return maxSum;
}
