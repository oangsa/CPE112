//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;

    int isRightThreaded;
    int isLeftThreaded;
} tree;

tree* createNode(int data);
tree* insert(tree* root, int data);
tree* inOrderSucessor(tree* root);

void inOrder(tree* root);

int main(void) {
    tree* root = NULL;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 13);

    inOrder(root);

    return 0;
}

tree* createNode(int data) {
    tree* newNode = (tree*) malloc(sizeof(tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isLeftThreaded = 1;
    newNode->isRightThreaded = 1;

    return newNode;
}

tree* insert(tree* root, int data) {
    tree* newNode = createNode(data);

    if (root == NULL) {
        root = newNode;
    }
    else {
        tree* ptr = root;
        tree* preptr = NULL;

        while (ptr != NULL) {
            preptr = ptr;

            if (data >= ptr->data) {
                // Right
                if (!ptr->isRightThreaded) ptr = ptr->right;
                else break;
            }
            else {
                // Left
                if (!ptr->isLeftThreaded) ptr = ptr->left;
                else break;
            }
        }

        if (preptr == NULL) {
            root = newNode;
        }
        else if (data >= preptr->data) {
            // Right
            newNode->left = preptr;
            newNode->right = preptr->right;
            preptr->isRightThreaded = 0;
            preptr->right = newNode;
        }
        else {
            // Left
            newNode->left = preptr->left;
            newNode->right = preptr;
            preptr->isLeftThreaded = 0;
            preptr->left = newNode;
        }
    }

    return root;
}

tree* inOrderSucessor(tree* root) {
    if (root->isRightThreaded) return root->right;

    root = root->right;
    while (!root->isLeftThreaded) {
        root = root->left;
    }

    return root;
}

void inOrder(tree* root) {
    if (!root) {
        printf("Tree is empty.\n");
        return;
    }

    tree* ptr = root;
    // Reach leftmost node
    while (!ptr->isLeftThreaded) ptr = ptr->left;

    // Print Successor one by one
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = inOrderSucessor(ptr);
    }
    printf("\n");
}
