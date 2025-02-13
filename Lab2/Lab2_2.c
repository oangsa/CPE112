//Suthang Sukrueangkun
//67070503477

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int pos[99999] = {-1};

    int size;
    int target;

    char a = '0';

    scanf("%d", &size);
    scanf("%d", &target);

    int arr[size];

    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);

        pos[a + arr[i]] = i;
    }

    for(int i = 0; i < size; i++) {
        if (pos[a + (target - arr[i])] != 0) {
            printf("%d %d", pos[a + arr[i]], pos[a + (target - arr[i])]);

            return 0;
        }
    }



    return 0;
}
