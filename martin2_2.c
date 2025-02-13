//Pawarit Wongdaeng
//67070503466
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};


void insertNodeEnd(struct node **head, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *last = *head;
    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL) {
        *head = newNode;
        newNode -> next= *head;
    }
    else {
        while (last->next != *head) {
            last = last -> next;
        }
        last -> next = newNode;
    }
}

int main() {
    struct node *head = NULL;
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    for(int i = 1; i <= n; i++) {
        insertNodeEnd(&head, i);
    }


    while(head -> next != head) {
        for(int i = 1; i < k-1; i++) {
            head = head -> next;
        }
        struct node *temp = head -> next;
        head -> next = temp -> next;
        free(temp);
        head = head -> next;
    }

    printf("%d", head -> data);

    return 0;
}
