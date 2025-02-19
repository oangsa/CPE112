#include <stdio.h>

void doSieve(int arr[], int size);

int main(void) {
    int num;
    scanf("%d", &num);

    int sieve[999999] = {0}; // 0 = prime 1 = not prime

    doSieve(sieve, num);

    if (!sieve[num]) {
        printf("%d is prime.\n", num);
    }
    else {
        printf("%d is not prime.\n", num);
    }

    return 0;
}

void doSieve(int arr[], int size) {

    arr[0] = arr[1] = 1;

    for (int i = 2; i * i <= size; i++) {
        if (arr[i] == 0) {
            for (int j = i * i; j <= size; j += i) {
                arr[j] = 1;
            }
        }
    }
}
