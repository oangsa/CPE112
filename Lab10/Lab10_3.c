// Suthang Sukrueangkun
// 67070503477

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct hash {
    char* data;
    int key;
} hash_t;

typedef struct node {
    hash_t value;
    struct node* next;
} node_t;

typedef struct table {
    int size;
    node_t** list;
} table_t;

table_t table;

int hash(int key);
void put(char* data, int key);
void search(int key);
void delete(int key);
node_t* createNode(char* data, int key);

int main(void) {
    char cmd[99];
    char data[999];
    int key;

    scanf(" %d", &table.size);

    table.list = (node_t**) malloc(table.size * sizeof(node_t*));

    for (int i = 0; i < table.size; i++) table.list[i] = NULL;

    while(1) {
        scanf(" %s", cmd);

        if (strcmp(cmd, "Insert") == 0) {
            scanf(" %d %s", &key, data);
            put(data, key);
        }
        else if (strcmp(cmd, "Search") == 0) {
            scanf(" %d", &key);
            search(key);
        }
        else if (strcmp(cmd, "Delete") == 0) {
            scanf(" %d", &key);
            delete(key);
        }
        else if (strcmp(cmd, "Exit") == 0) break;
    }

    printf("Hash Table:\n");
    for (int i = 0; i < table.size; i++) {
        printf("[%d]", i);

        node_t* tmp = table.list[i];
        while (tmp) {
            printf(" -> %s", tmp->value.data);
            tmp = tmp->next;
        }
        printf("\n");
    }
    return 0;
}

int hash(int key) {
    return key % table.size;
}

node_t* createNode(char* data, int key) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->value.data = (char*) malloc(strlen(data) + 1);
    node->value.key = key;
    strcpy(node->value.data, data);
    node->next = NULL;

    return node;
}

void put(char* data, int key) {
    int idx = hash(key);
    node_t* newNode = createNode(data, key);

    node_t* tmp = table.list[idx];

    printf("Inserted key %d at index %d\n", key, idx);

    if (!tmp) {
        table.list[idx] = newNode;
        return;
    }

    while(tmp->next) {
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

void search(int key) {
    int idx = hash(key);

    node_t* tmp = table.list[idx];

    while (tmp) {
        if (tmp->value.key == key) {
            printf("Found: %s\n", tmp->value.data);
            return;
        }

        tmp = tmp->next;
    }

    printf("%d is not found.\n", key);
}

void delete(int key) {
    int idx = hash(key);

    node_t* tmp = table.list[idx];
    node_t* preptr = NULL;

    while (tmp) {
        if (tmp->value.key == key) break;
        preptr = tmp;
        tmp = tmp->next;
    }

    if (!tmp) {
        printf("Key %d not found for deletion\n", key);
        return;
    }

    if (!preptr) {
        table.list[idx] = tmp->next;
        free(tmp->value.data);
        free(tmp);
        printf("Deleted %d from index %d\n", key, idx);
        return;
    }

    preptr->next = tmp->next;
    free(tmp->value.data);
    free(tmp);

    printf("Deleted %d from index %d\n", key, idx);
}
