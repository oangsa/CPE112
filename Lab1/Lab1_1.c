//Suthang Sukrueangkun
//67070503477

#include<stdio.h>

int main(void) {

    int size, ctr = 1;

    scanf("%d", &size);

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", ctr++);
        }
        printf("\n");
    }

    return 0;
}
