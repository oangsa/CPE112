// Suthang Sukrueangkun
// 67070503477

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 9999

int tb[MAX_SIZE] = {0};

int top = -1;
int size = 0; // Just In case I want to use the size so... Idk though

char opStack[MAX_SIZE];

void push(char op);
char pop();
char seek();

int main() {

    char eq[MAX_SIZE];

    tb['+'] = 1;
    tb['-'] = 1;
    tb['*'] = 2;
    tb['/'] = 2;
    tb['^'] = 3;

    scanf("%[^\n]s", eq);

    for (char* a = eq; *a != '\0'; a++) {
        char chr = *a;

        if (chr == '(') {
            push(chr);
            continue;
        }

        if (chr == ')') {
            char b = pop();
            while (b != '(') {
                printf("%c", b);
                b = pop();
            }

            continue;
        }

        if (tb[chr]) {
            if (top == -1) {
                push(chr);
                continue;
            }
            if (tb[seek()] == tb[chr]) {
                printf("%c", pop());
                push(chr);
                continue;
            }

            if (tb[seek()] > tb[chr]) {
                while(top > -1 && seek() != '(') {
                    printf("%c", pop());
                }
            }

            push(chr);
            continue;
        }

        printf("%c", chr);

    }

    while (top > -1) {
        printf("%c", pop());
    }

    return 0;
}

void push(char op) {
    opStack[++top] = op;
    size++;
}

char pop() {
    return opStack[top--];
}

char seek() {
    return opStack[top];
}
