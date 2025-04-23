#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

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

// Webhook configuration (would normally be in a config file)
const char* WEBHOOK_URL = "https://discord.com/api/webhooks/1364538746401329213/vYRmcEyv8R8EWjslW3ZLyQddHTa8enMY_4IWNPnyM-bLGpSF2PEmoubHExxhdeEljzI0";

// Function prototypes
int hash(int key);
void put(char* data, int key);
void search(int key);
void delete(int key);
node_t* createNode(char* data, int key);
void send_to_discord(const char* message);
char* escape_json(const char* str);

int main(void) {
    char cmd[99];
    char data[999];
    int key, isEmpty = 1;

    scanf(" %d", &table.size);

    table.list = (node_t**)malloc(table.size * sizeof(node_t*));
    for (int i = 0; i < table.size; i++) table.list[i] = NULL;

    while(1) {
        scanf(" %s", cmd);

        if (strcmp(cmd, "Insert") == 0) {
            scanf(" %d %s", &key, data);
            put(data, key);
            char message[1024];
            snprintf(message, sizeof(message), "Inserted key %d at index %d", key, hash(key));
            send_to_discord(message);
        }
        else if (strcmp(cmd, "Search") == 0) {
            scanf(" %d", &key);
            search(key);
        }
        else if (strcmp(cmd, "Delete") == 0) {
            scanf(" %d", &key);
            delete(key);
        }
        else if (strcmp(cmd, "Exit") == 0) {
            send_to_discord("Hash table program terminated");
            break;
        }
        else {
            printf("Invalid command. Try again.\n");
        }
    }

    // Generate and send final hash table state
    char output[4096] = "Final Hash Table State:\n";
    for (int i = 0; i < table.size; i++) {
        char line[256];
        snprintf(line, sizeof(line), "[%d]", i);

        node_t* tmp = table.list[i];
        while (tmp) {
            isEmpty = 0;
            strcat(line, " -> ");
            strcat(line, tmp->value.data);
            tmp = tmp->next;
        }
        strcat(line, "\n");
        strcat(output, line);
    }
    
    if (isEmpty) {
        strcat(output, "Table is empty.\n");
    }
    
    send_to_discord(output);

    // Cleanup
    for (int i = 0; i < table.size; i++) {
        node_t* current = table.list[i];
        while (current != NULL) {
            node_t* temp = current;
            current = current->next;
            free(temp->value.data);
            free(temp);
        }
    }
    free(table.list);

    return 0;
}

// Hash function implementation
int hash(int key) {
    return key % table.size;
}

// Create a new node
node_t* createNode(char* data, int key) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->value.data = strdup(data);
    node->value.key = key;
    node->next = NULL;
    return node;
}

// Insert into hash table
void put(char* data, int key) {
    int idx = hash(key);
    node_t* newNode = createNode(data, key);

    if (!table.list[idx]) {
        table.list[idx] = newNode;
    } else {
        node_t* tmp = table.list[idx];
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

// Search in hash table
void search(int key) {
    int idx = hash(key);
    node_t* tmp = table.list[idx];
    char message[1024];

    while (tmp) {
        if (tmp->value.key == key) {
            snprintf(message, sizeof(message), "Found: %s (Key: %d, Index: %d)", 
                    tmp->value.data, key, idx);
            printf("%s\n", message);
            send_to_discord(message);
            return;
        }
        tmp = tmp->next;
    }

    snprintf(message, sizeof(message), "Key %d not found", key);
    printf("%s\n", message);
    send_to_discord(message);
}

// Delete from hash table
void delete(int key) {
    int idx = hash(key);
    node_t* tmp = table.list[idx];
    node_t* prev = NULL;
    char message[1024];

    while (tmp) {
        if (tmp->value.key == key) {
            if (prev) {
                prev->next = tmp->next;
            } else {
                table.list[idx] = tmp->next;
            }
            
            snprintf(message, sizeof(message), "Deleted key %d (Data: %s)", 
                    key, tmp->value.data);
            printf("%s\n", message);
            send_to_discord(message);
            
            free(tmp->value.data);
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }

    snprintf(message, sizeof(message), "Key %d not found for deletion", key);
    printf("%s\n", message);
    send_to_discord(message);
}

// Escape special JSON characters
char* escape_json(const char* str) {
    char* escaped = malloc(strlen(str) * 2 + 1); // Worst case: every char needs escaping
    size_t pos = 0;
    
    for (size_t i = 0; str[i] != '\0'; i++) {
        switch (str[i]) {
            case '"':  strcpy(escaped + pos, "\\\""); pos += 2; break;
            case '\\': strcpy(escaped + pos, "\\\\"); pos += 2; break;
            case '\b': strcpy(escaped + pos, "\\b");  pos += 2; break;
            case '\f': strcpy(escaped + pos, "\\f");  pos += 2; break;
            case '\n': strcpy(escaped + pos, "\\n");  pos += 2; break;
            case '\r': strcpy(escaped + pos, "\\r");  pos += 2; break;
            case '\t': strcpy(escaped + pos, "\\t");  pos += 2; break;
            default:
                if (str[i] < 32) {
                    // Skip control characters
                } else {
                    escaped[pos++] = str[i];
                }
        }
    }
    escaped[pos] = '\0';
    return escaped;
}

// Send message to Discord using system curl
void send_to_discord(const char* message) {
    char* escaped = escape_json(message);
    char command[4096];
    
    snprintf(command, sizeof(command),
        "curl -s -X POST -H \"Content-Type: application/json\" "
        "-d '{\"content\":\"```\\n%s\\n```\"}' "
        "\"%s\" >/dev/null 2>&1",
        escaped, WEBHOOK_URL);
    
    system(command);
    free(escaped);
}
