// Suthang Sukrueangkun
// 67070503477

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct hash{
    int isUse;
    int key;
    char* data;
} hash_t;

typedef struct table {
    int size;
    int datactr;
    hash_t* table;
} table_t;

table_t table = {
    .size = 0,
    .datactr = 0
};

int hash(int key);
void push(char* data, int key);
void search(int key);

int main(void) {
    char cmd[99];
    char data[999];
    int key;

    scanf(" %d", &table.size);

    table.table = (hash_t*) malloc(table.size * sizeof(hash_t));

    while(1) {
        scanf(" %s", cmd);

        if (strcmp(cmd, "Insert") == 0) {
            scanf(" %d %s", &key, data);
            push(data, key);
        }
        else if (strcmp(cmd, "Search") == 0) {
            scanf(" %d", &key);
            search(key);
        }
        else if (strcmp(cmd, "Exit") == 0) break;
    }

    if (table.datactr == 0) {
        printf("Hash table is empty.\n");
        return 0;
    }

    printf("Hash Table:\n");
    for (int i = 0; i < table.size; i++) {
        printf("[%d] ", i);
        if (table.table[i].isUse != 1) {
            printf("---\n");
            continue;
        }

        printf("Key: %d, String: %s\n", table.table[i].key, table.table[i].data);
    }


    return 0;
}

int hash(int key) {
    int i = 0;
    int ctr = 0;
    int startIndex = key % table.size;

    while (1) {
        int index = (key + i) % table.size;
        if (ctr == table.size) return -1;
        if (table.table[index].isUse != 1) return index;
        if (table.table[index].isUse == 1 && table.table[index].key == key) return index;
        i++;
        ctr++;
    }
}

// index = -1 means table is full;
void push(char* data, int key) {
    int index = hash(key);


    if (index == -1) {
        printf("Hash table is full.\n");
        return;
    }

    if (table.table[index].isUse && table.table[index].key == key) {
        table.table[index].data = (char*) realloc(table.table[index].data, sizeof(strlen(data) + 1));

        strcpy(table.table[index].data, data);

        printf("Updated key %d at index %d\n", key, index);

        return;
    }


    table.table[index].isUse = 1;
    table.table[index].key = key;
    table.table[index].data = (char*) malloc(sizeof(strlen(data) + 1));

    printf("Inserted key %d at index %d\n", key, index);
    table.datactr++;
    strcpy(table.table[index].data, data);
}

void search(int key) {
    int index = hash(key);

    if (index == -1 || table.table[index].key != key) {
        printf("%d is not found.\n", key);
        return;
    }

    printf("Found: %s\n", table.table[index].data);
}
