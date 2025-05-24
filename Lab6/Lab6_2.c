//Suthang Sukrueangkun
//67070503477

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} tree;

tree* root = NULL;

void preOrder(tree* root);
void postOrder(tree* root);
void inOrder(tree* root);

tree* createNode(int val);

int main(void) {
    int n;
    int rootVal;

    char cmd[999];

    scanf(" %d", &n);
    scanf(" %d", &rootVal);

    root = createNode(rootVal);

    for (int i = 0; i < n - 1; i++) {
        scanf("%s %d", cmd, &rootVal);

        tree* r = root;
        int len = strlen(cmd);
        int i;
        for (i = 0; i < len - 1; i++ ) {
            if (cmd[i] == 'L') r = r->left;
            else if (cmd[i] == 'R') r = r->right;
        }
        if (cmd[i] == 'L') r->left = createNode(rootVal);
        else if (cmd[i] == 'R') r->right = createNode(rootVal);
    }

    preOrder(root);

}

tree* createNode(int val) {
    tree* newNode = (tree*) malloc(sizeof(tree));
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void preOrder(tree* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(tree* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->value);
    }
}

void inOrder(tree* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}
