#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10007

// ================= HASH TABLE =================

typedef struct HashNode {
    char *key;              // sorted string
    int index;              // index in result array
    struct HashNode *next;
} HashNode;

HashNode *table[TABLE_SIZE];

// hash function for string
unsigned int hash(char *s) {
    unsigned int h = 0;
    while (*s) {
        h = h * 31 + *s;
        s++;
    }
    return h % TABLE_SIZE;
}

// find key
HashNode* find(char *key) {
    unsigned int idx = hash(key);
    HashNode *cur = table[idx];
    while (cur) {
        if (strcmp(cur->key, key) == 0)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

// insert key
void insert(char *key, int index) {
    unsigned int idx = hash(key);
    HashNode *node = malloc(sizeof(HashNode));
    node->key = strdup(key);
    node->index = index;
    node->next = table[idx];
    table[idx] = node;
}

// ================= STRING SORT =================

int cmp(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

char* sortedCopy(char *s) {
    char *copy = strdup(s);
    qsort(copy, strlen(copy), sizeof(char), cmp);
    return copy;
}

// ================= MAIN FUNCTION =================

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    memset(table, 0, sizeof(table));

    char ***result = malloc(strsSize * sizeof(char**));
    *returnColumnSizes = malloc(strsSize * sizeof(int));

    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {
        char *key = sortedCopy(strs[i]);
        HashNode *node = find(key);

        if (node) {
            // existing group
            int idx = node->index;
            int size = (*returnColumnSizes)[idx];
            result[idx] = realloc(result[idx], (size + 1) * sizeof(char*));
            result[idx][size] = strdup(strs[i]);
            (*returnColumnSizes)[idx]++;
        } else {
            // new group
            result[groupCount] = malloc(sizeof(char*));
            result[groupCount][0] = strdup(strs[i]);
            (*returnColumnSizes)[groupCount] = 1;
            insert(key, groupCount);
            groupCount++;
        }
        free(key);
    }

    *returnSize = groupCount;
    return result;
}
