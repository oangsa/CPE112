//Suthang Sukrueangkun
//67070503477

#include<stdio.h>

#define MAX_SIZE 99999

char stack[MAX_SIZE];
int top = -1;

void push(char a);
void pop();

int main(void) {

    char a[MAX_SIZE];

    scanf("%s", a);

    for (char* s = a; (*s) != '\0'; s++) {
        push(*s);
    }

    printf("Old: %s\n", a);
    printf("Reversed: ");

    while (top != -1) {
        pop();
    }

    printf("\n");


    return 0;
}

void push(char a) {
    stack[++top] = a;
}

void pop() {
    printf("%c", stack[top--]);
}
