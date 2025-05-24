// Suthang Sukrueangkun
// 67070503477

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

typedef struct hash {
    int key;
    int isOccupied;
    char* value;
} hash_t;

typedef struct table {
    int size;
    hash_t table[SIZE];
} table_t;

table_t table = {
    .size = 0
};

void search(int key);
void put(char* data, int key);
void delete(int key);
int hash(int key);

int main(void) {
    char cmd[99];
    char data[999];
    int key;

    while(1) {
        scanf(" %s", cmd);

        if (strcmp(cmd, "INSERT") == 0) {
            scanf(" %d %s", &key, data);
            put(data, key);
        }
        else if (strcmp(cmd, "SEARCH") == 0) {
            scanf(" %d", &key);
            search(key);
        }
        else if (strcmp(cmd, "DELETE") == 0) {
            scanf(" %d", &key);
            delete(key);
        }
        else if (strcmp(cmd, "END") == 0) break;
    }

    if (table.size < 1) {
        printf("Table is empty.\n");
        return 0;
    }

    for (int i = 0; i < SIZE; i++) {
        if (table.table[i].isOccupied != 1) continue;

        printf("Index %d: %d %s\n", i, table.table[i].key, table.table[i].value);
    }

    return 0;
}

int hash(int key) {return key % SIZE;}

void put(char* data, int key) {
    int index = hash(key);
    
    if (table.table[index].isOccupied) {
        printf("Index %d is occupied.\n", index);
        return;
    }

    table.table[index].isOccupied = 1;
    table.table[index].key = key;
    table.table[index].value = malloc(sizeof(strlen(data) + 1));

    strcpy(table.table[index].value, data);
    table.size++;

    printf("Inserted key %d at index %d.\n", key, index);
}

void search(int key) {
    int index = hash(key);

    if (table.table[index].isOccupied != 1 || table.table[index].key != key) {
        printf("%d is not found.\n", key);
        return;
    }

    printf("%d %s\n", index, table.table[index].value);
}

void delete(int key) {
    hash_t h;
    int index = hash(key);

    table.table[index] = h;
    table.size--;
}
