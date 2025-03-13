//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;
} tree;

tree* createNode(int value);
void insert(int value);

void inOrder(tree* root);
void postOrder(tree* root);
void preOrder(tree* root);

tree* root = NULL;

int main(void) {
    int count;
    int value;

    scanf(" %d", &count);

    for (int i = 0; i < count; i++) {
        scanf(" %d", &value);
        insert(value);

    }

    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    return 0;
}

tree* createNode(int value) {
    tree* newNode = (tree*) malloc(sizeof(tree));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insert(int value) {
    tree* newNode = createNode(value);

    if (!root) {
        root = newNode;
    }
    else {
        tree* cur = root;
        tree* preptr = NULL;

        while (cur != NULL) {
            preptr = cur;

            if (value >= cur->data) cur = cur->right;
            else {
                cur = cur->left;
            }
        }

        if (preptr->data > value) preptr->left = newNode;
        else {
            preptr->right = newNode;
        }
    }
}

void inOrder(tree* root) {
    if (!root) return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(tree* root) {
    if (!root) return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(tree* root) {
    if (!root) return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
