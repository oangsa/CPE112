// Suthang Sukrueangkun
// 67070503477
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 999999

char stack[MAX_SIZE];
int top = -1;
int size = 0;

void push(char chr);
char pop();

int main() {
    char str[MAX_SIZE];

    scanf("%s", str);

    for (char* a = str; *a != '\0'; a++) {
        // printf("%c", *a);
        push(*a);
    }

    for (int i = 0; i < size; i++) {
        char a = pop();
        // printf("%c\n", a);

        if (a != str[i]) {
            printf("no");
            return 1;
        }
    }

    printf("yes");

    return 1;
}

void push(char chr) {
    if (top == MAX_SIZE - 1) {
        printf("Array is full\n");
        return;
    }

    stack[++top] = chr;
    size++;

}

char pop() {
    return stack[top--];
}
