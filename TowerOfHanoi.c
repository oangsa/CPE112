//Suthang Sukrueangkun
//67070503477

#include<stdio.h>

int stepHanoi(int num) {
    if (num == 1) return 1;
    else return 2 * stepHanoi(num-1) + 1;
}

int main(void) {

    printf("%d", stepHanoi(3));

    return 0;
}
