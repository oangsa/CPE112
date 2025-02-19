#include<stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    // 2 3 5 7 11
    if (n <= 1) {
        printf("%d is not a prime number\n", n);
        return 1;
    }
    else if (n == 2 || n == 3 || n == 5) {
        printf("%d is a prime number\n", n);
        return 1;
    }
    else {
        for (int i = 5; i * i <= n; i+=6) {
            if (n % i == 0) {
                printf("%d is not a prime number\n", n);

                return 1;
            }
        }
    }

    printf("%d is a prime number\n", n);

    return 0;
}
