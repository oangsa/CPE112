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
void depthFirstSearch(struct node* root);
int internalNodesCount(struct node* root);

int main() {

    insertNode(10);
    insertNode(5);
    insertNode(15);
    insertNode(16);
    insertNode(18);
    insertNode(18);
    insertNode(17);
    insertNode(13);
    insertNode(3);

    depthFirstSearch(t);
    printf("\n");

    printf("Internal Node(s) Count: %d\n", internalNodesCount(t));



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
            if (t->data > data) t = t->left;
            else t = t->right;
        }
        if (preptr->data > data) preptr->left = newTree;
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

void deleteNode(int data) {
    if (!t) {
        printf("Tree is empty.\n");
        return;
    }

    tree* preptr = NULL;
    tree* root = t;

    while (root != NULL && root->data != data) {
        preptr = root;

        if (data >= root->data) root = root->right;
        else root = root->left;
    }

    if (root == NULL) {
        printf("Provided data not found.\n");
        return;
    }

    if (root->right == NULL && root->left == NULL) {
        // Don't have any node on both sides
        if (preptr == NULL) {
            // Only root node
            free(t);
            t = NULL;
        }
        else if (preptr->left == root) {
            preptr->left = NULL;
            free(root);
        }
        else {
            preptr->right = NULL;
            free(root);
        }
    }
    else if (!root->right) {
        // Only have left side
        if (preptr == NULL) {
            // Root node with only left child
            t = root->left;
        }
        else if (preptr->right == root) {
            preptr->right = root->left;
        }
        else {
            preptr->left = root->left;
        }
        free(root);
        root = NULL;
    }
    else if (!root->left) {
        // Only have right side
        if (preptr == NULL) {
            // Root node with only right child
            t = root->right;
        }
        else if (preptr->right == root) {
            preptr->right = root->right;
        }
        else {
            preptr->left = root->right;
        }
        free(root);
        root = NULL;
    }
    else {
        // Have both nodes
        tree* preTmp = NULL;
        tree* tmp = root->right;

        // Find the smallest node in the right subtree
        while (tmp->left != NULL) {
            preTmp = tmp;
            tmp = tmp->left;
        }

        // Replace the node that will be deleted with the smallest node in the right subtree
        root->data = tmp->data;


        // Delete the smallest node in the right subtree
        if (preTmp) {
            // If the smallest node in the right subtree has a left child
            preTmp->left = tmp->right;
        }
        else {
            // If the smallest node in the right subtree doesn't have a left child
            root->right = tmp->right;
        }

        free(tmp);
        tmp = NULL;
    }
}

void displayBST(struct node* n) {
    if (n == NULL) return;

    displayBST(n->left);
    printf("%d ", n->data);
    displayBST(n->right);

}

void depthFirstSearch(struct node* root) {
    tree* queue[999];
    int front = 0, rear = -1;

    tree* r = root;
    queue[++rear] = r;

    while (queue[front] != NULL) {
        // dequeue
        printf("%d ", queue[front++]->data);

        if (queue[front - 1]->left != NULL) queue[++rear] = queue[front - 1]->left;

        if (queue[front - 1]->right != NULL) queue[++rear] = queue[front - 1]->right;
    }
}

int internalNodesCount(struct node* root) {
    if (!root) return 0;

    return 1 + internalNodesCount(root->left) + internalNodesCount(root->right);
}
