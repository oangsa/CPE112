//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int num, idx = 0;
    char *arr = (char*) malloc(999 * sizeof(char));


    scanf("%d", &num);

    if (num == 0) {
        printf("%c", '0');
        free(arr);
        return 0;
    }

    while (num > 0) {
        int remainder = num % 16;
        // printf("%d\n", remainder);
        if (remainder < 10) arr[idx++] = '0' + remainder;
        else arr[idx++] = 'A' + (remainder % 10);
        num /= 16;
    }

    arr[idx] = '\0';

    for (int i = idx-1; i >= 0; i--) {
        printf("%c", arr[i]);
    }


    free(arr);
    return 0;
}
