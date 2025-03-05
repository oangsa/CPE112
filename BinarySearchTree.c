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
void deleteNode(int data);

int main() {

    insertNode(10);
    insertNode(5);
    insertNode(15);
    insertNode(3);

    displayBST(t);
    printf("\n");

    deleteNode(100);

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

// void deleteNode(int data) {
//     if (!t) {
//         printf("Tree is empty\n");

//         return;
//     }
//     else {
//         tree* cur = t;
//         tree* prev = NULL;

//         while (cur != NULL && cur->data != data) {
//             prev = cur;

//             if (data < cur->data) cur = cur->left;
//             else cur = cur->right;
//         }

//         // printf("Found! '%d'\n", cur->left->data);

//         if (!cur) {
//             printf("The entered data is not exist in the tree.\n");
//         }
//         else {
//             if (cur->left == NULL && cur->right == NULL) {
//                 if (!prev) {
//                     t = NULL;
//                 }
//                 else {
//                     if (prev->left->data == cur->data) {
//                         prev->left = NULL;
//                     }
//                     else {
//                         prev->right = NULL;
//                     }
//                 }
//             }
//             else {
//                 if (!cur->left) {
//                     if (!prev) {
//                         t = NULL;
//                     }
//                     else {
//                         if (!prev->right) {
//                             prev->right = cur->right;
//                         }
//                         else {
//                             prev->left = cur->right;
//                             free(cur);
//                             cur = NULL;
//                         }
//                     }
//                 }
//                 else if (!cur->right) {
//                     // printf("TEST\n");
//                     if (!prev) {
//                         t = NULL;
//                     }
//                     else {
//                         if (!prev->left) {
//                             prev->left = cur->left;
//                         }
//                         else {
//                             prev->right = cur->left;
//                             cur = NULL;
//                         }
//                     }
//                 }
//                 else {
//                     tree* tmp = cur->right;
//                     tree* prevTmp = NULL;

//                     while (tmp->left != NULL) {
//                         prevTmp = tmp;
//                         tmp = tmp->left;
//                     }

//                     cur->data = tmp->data;
//                     if (prevTmp) prevTmp->left = NULL;
//                     else cur->right = NULL;

//                     free(tmp);
//                     tmp = NULL;
//                 }
//             }
//         }
//     }
// }

void deleteNode(int data) {
    // GPT Generated Code

    if (!t) {
        printf("Tree is empty\n");
        return;
    }

    tree* cur = t;
    tree* prev = NULL;

    while (cur != NULL) {
        prev = cur;

        if (cur->)

        if (data < cur->data) cur = cur->left;
        else cur = cur->right;
    }

    printf("ad\n");
    printf("%d\n", cur->data);

    if (cur == NULL) {
        printf("The entered data doesnt exit in the tree\n");
        return;
    }

    if (!cur->left || !cur->right) {
        tree* tmp;

        if (!cur->left) tmp = cur->right;
        else tmp = cur->right;

        if (!prev) {
            t = tmp;
        }
        else if (cur == prev->left) {
            prev->left = tmp;
        }
        else {
            prev->right = tmp;
        }

        free(cur);
    }
    else {
        tree* tmp = cur->right;
        tree* prevTmp = cur;

        while(tmp->left != NULL) {
            prevTmp = tmp;
            tmp = tmp->left;
        }

        if (prevTmp->left == tmp) {
            prevTmp->left = tmp->right;
        }
        else {
            prevTmp->right = tmp->right;
        }

        free(tmp);

    }
}

void displayBST(struct node* n) {
    if (n == NULL) return;

    displayBST(n->left);
    printf("%d ", n->data);
    displayBST(n->right);

}
