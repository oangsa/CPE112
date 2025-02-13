//Suthang Sukrueangkun
//67070503477

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int ab[99999] = {0};

    int size;
    int target;

    scanf("%d", &size);
    scanf("%d", &target);

    int arr[size];

    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        ab[arr[i]] = i;
    }


    for(int i = 0; i < size; i++) {
        if(ab[target - arr[i]] != 0) {
            printf("%d %d", ab[arr[i]], ab[target - arr[i]]);
            return 0;
        }
    }

    return 0;
}
