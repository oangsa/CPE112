//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void towerOfHanoi(int num, char f_rod, char to_rod, char aux_rod);

int main(void) {

    towerOfHanoi(4, 'A', 'C', 'B');

    return 0;
}

void towerOfHanoi(int num, char f_rod, char to_rod, char aux_rod) {
    if (num == 0) return;

    towerOfHanoi(num - 1, f_rod, aux_rod, to_rod);
    printf("move disk %d from rod %c to %c\n", num, f_rod, to_rod);
    towerOfHanoi(num-1, aux_rod, to_rod, f_rod);

}
