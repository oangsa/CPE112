//Suthang Sukrueangkun
//67070503477

#include<stdio.h>

int sumBU(int n);
int sumTD(int n);

int main(void) {
    int n;

    scanf("%d", &n);

    printf("Sum from 1 to %d is %d\n", n, sumBU(n));
    printf("Sum from 1 to %d is %d\n", n, sumTD(n));

    return 0;
}

int sumTD(int n) {
    if (n == 0 || n == 1) return n;
    return n += sumBU(n - 1);
}

int sumBU(int n) {
    int res = 0;
    for(int i = 1; i <= n; i++) res += i;
    return res;
}
