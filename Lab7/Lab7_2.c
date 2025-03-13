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

void findMin(tree* node, int* min); // preOrder
void findMax(tree* node, int* max); // postOrder

tree* root = NULL;

int main(void) {
    int count;
    int value;

    int min = 999999;
    int max = -999999;

    scanf(" %d", &count);

    for (int i = 0; i < count; i++) {
        scanf(" %d", &value);
        insert(value);
    }

    findMin(root, &min);
    findMax(root, &max);

    printf("%d \n%d \n", min, max);


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

void findMin(tree* node, int* min) {
    if (!node) return;

    if (root->data == node->data) *min = root->data;
    if (*min > node->data) *min = node->data;

    findMin(node->left, min);
    findMin(node->right, min);
}

void findMax(tree* node, int* max) {
    if (!node) return;

    if (root->data == node->data) *max = root->data;
    if (*max < node->data) *max = node->data;

    findMax(node->left, max);
    findMax(node->right, max);
}
