// Suthang Sukrueangkun
// 67070503477

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} n;

int size = 0;

n* lst = NULL;

n** head = &lst;
n* tail = NULL;

void push(int d);
void printList();
void pop();
void peek();

int main(void) {
    push(1);
    push(2);
    push(3);
    peek();
    push(4);

    pop();
    pop();
    pop();
    pop();

    printList();

    return 0;
}

void push(int d) {
    n* newNode = (n*) malloc(sizeof(n));
    newNode->next = *head;
    newNode->data = d;

    if (!lst) {
        lst = newNode;
        lst->next = newNode;

        tail = newNode;
    }
    else {
        tail->next = newNode;

        tail = newNode;
    }

}

void pop() {
    if (!(*head)) {
        printf("List is empty.\n");

        return;
    }
    else if (*head == (*head)->next) {
        printf("%d has been popped.\n", (*head)->data);

        free(*head);
        *head = NULL;
    }
    else {
        n* preptr = *head;

        while (preptr->next->next != *head) {
            preptr = preptr->next;
        }

        n* last = preptr->next;
        preptr->next = *head;

        printf("%d has been popped.\n", last->data);

        free(last);

    }
}

void peek() {
    if (!(*head)) {
        printf("List is empty.\n");

        return;
    }

    printf("%d\n", tail->data);
}

void printList() {

    if (*head == NULL) {
        printf("List is empty.\n");

        return;
    }

    n* h = (*head);


    do {
        printf("%d ", h->data);
        h = h->next;
    } while(h != *head);

    printf("\n");

}
