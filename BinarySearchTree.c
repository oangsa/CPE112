#include<stdio.h>
#include<stdlib.h>

// BST
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} tree;

tree* t = NULL;

void insertNode(int data);
void search(int data);
void displayBST(struct node* n);

int main() {

    insertNode(50);
    insertNode(100);
    insertNode(75);

    printf("Searching...\n");

    search(10);
    search(50);
    search(75);
    search(100);

    displayBST(t);

    return 0;
}

void insertNode(int data) {
    tree* newTree = (tree*) malloc(sizeof(tree));
    newTree->data = data;
    newTree->left = NULL;
    newTree->right = NULL;

    if (t == NULL) {
        t = newTree;
    }
    else {
        tree* tmp = t;
        tree* preptr = NULL;

        while (t != NULL) {
            preptr = t;
            if (t->data >= data) t = t->left;
            else t = t->right;
        }
        if (preptr->data >= data) preptr->left = newTree;
        else preptr->right = newTree;

        t = tmp;
    }
}

void search(int value) {
    if (t == NULL) {
        printf("Binary tree is empty.\n");

        return;
    }
    else {
        tree* tmp = t;

        while (tmp != NULL) {
            if(tmp->data == value) {
                printf("Found '%d'\n", tmp->data);
                return;
            }
            if (tmp == NULL) {
                break;
            }
            if (tmp->data >= value) tmp = tmp->left;
            else tmp = tmp->right;

        }

        printf("Not Found!\n");

    }
}

void displayBST(struct node* n) {
    if (n == NULL) return;

    displayBST(n->left);
    printf("%d ", n->data);
    displayBST(n->right);

}
