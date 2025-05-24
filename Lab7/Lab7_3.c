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
void deleteNode(int value);

void inOrder(tree* root);
void postOrder(tree* root);
void preOrder(tree* root);

tree* root = NULL;

int main(void) {
    int count;
    int value;

    char cmd[999];

    scanf(" %d", &count);

    while (1) {
        scanf(" %s", cmd);

        if (strcmp("INSERT", cmd) == 0) {
            scanf(" %d", &value);
            insert(value);
        }

        if (strcmp("DEL", cmd) == 0) {
            scanf(" %d", &value);
            deleteNode(value);
        }

        if (strcmp("END", cmd) == 0) break;
    }

    if (!root) {
        printf("Tree is empty.\n");
        return 0;
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

void deleteNode(int value) {
    tree* cur = root;
    tree* preptr = NULL;

    while (cur != NULL && cur->data != value) {
        preptr = cur;

        if (cur->data > value) cur = cur->left;
        else {
            cur = cur->right;
        }
    }

    if (cur == NULL) {
        printf("Node not found.\n");
        return;
    }

    // No Node both sides
    if (!cur->left && !cur->right) {

        if (!preptr) {
            free(root);
            root = NULL;
        }

        else if (preptr->left == cur) {
            preptr->left = NULL;
            free(cur);
        }
        else {
            preptr->right = NULL;
            free(cur);
        }
    }
    else if (!cur->left) {
        // Only right
        if (preptr == NULL) {
            // root with only right side
            root = cur->right;
        }
        else if (preptr->left == cur) {
            preptr->left = root->right;
        }
        else {
            preptr->right = root->right;
        }
        free(cur);
        cur = NULL;
    }
    else if (!cur->right) {
        // Only left
        if (preptr == NULL) {
            // root with only left side
            root = cur->left;
        }
        else if (preptr->left == cur) {
            preptr->left = root->left;
        }
        else {
            preptr->right = root->left;
        }
        free(cur);
        cur = NULL;
    }
    else {
        tree* tmp = cur->right;
        tree* preTmp = NULL;

        while (tmp->left != NULL) {
            preTmp = tmp;
            tmp = tmp->left;
        }

        cur->data = tmp->data;

        if (preTmp) {
            preTmp->left =  tmp->right;
        }
        else {
            cur->right = tmp->right;
        }

        free(tmp);
        tmp = NULL;
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
