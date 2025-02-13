//sorawit chaithong 67070503442
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void add(Node** n,int value){
    Node* newnode = (Node*) malloc(sizeof(Node));
    newnode -> data = value;
    newnode -> prev = NULL;
    newnode -> next = NULL;
    if(*n == NULL){
        *n = newnode;
    }else{
        Node* now = *n;
        while(now->next != NULL){
            now = now -> next;
        }
        now -> next = newnode;
        newnode -> prev = now;
    }
}
void rem(Node** n,int value){
    Node* now = *n;
    while(now != NULL ){
        if (now->data = value) {
            if (now->prev == NULL)  *n = now->next;

            else now->prev->next = now->next;

            if (now->next != NULL) now->next->prev = now->prev;

            free(now);
            return;
        }

        now = now->next;
    }
}

void search(Node* n, int value) {
    Node* now = n;

    while (now != NULL) {

        if (now->data == value) {
            if (now->prev == NULL) printf("NULL ");
            else printf("%d ", now->prev->data);

            if (now->next == NULL) printf("NULL\n");
            else printf("%d\n", now->next->data);

            return;
        }

        now = now->next;
    }

    printf("none\n");
}

void printList(Node** n) {
    Node* now = *n;
    Node* prev = NULL;

    if (now == NULL) {
        printf("none\nnone");

        return;
    }

    while (now != NULL) {
        printf("%d ", now->data);
        prev = now;
        now = now->next;
    }

    printf("\n");

    while (prev != NULL) {
        printf("%d ", prev->data);

        Node* a = prev;
        prev = prev->prev;

        free(a);
    }

    free(now);
    free(prev);
}

int main(){
    int value;
    char com[100];
    Node* head = NULL;

    while (1) {
        scanf("%s", com);

        if (strcmp(com, "END") == 0) break;

        scanf("%d", &value);

        if (strcmp(com, "ADD") == 0) add(&head, value);
        else if (strcmp(com, "DEL") == 0) rem(&head, value);
        else if (strcmp(com, "SCH") == 0) search(head, value);
    }

    printList(&head);

    return 0;
}
