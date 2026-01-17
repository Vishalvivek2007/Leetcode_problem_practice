#include <stdio.h>
#include <stdlib.h>

#define MAP_LEN 20005

/* ================= STRUCTS ================= */

struct node {
    int val;
    int freq;
    int idx;
};

struct mnode {
    int key;
    struct node* hptr;
    struct mnode* next;
};

struct maxheap {
    int len;
    struct node** arr;
};

/* ================= HASH ================= */

int gethash(int num) {
    return ((num % MAP_LEN) + MAP_LEN) % MAP_LEN;
}

/* ================= HEAP ================= */

struct node* createnode(int val) {
    struct node* n = malloc(sizeof(struct node));
    n->val = val;
    n->freq = 1;
    n->idx = -1;
    return n;
}

struct maxheap* createmaxheap() {
    struct maxheap* h = malloc(sizeof(struct maxheap));
    h->len = 0;
    h->arr = NULL;
    return h;
}

void swap(struct node** a, struct node** b) {
    struct node* t = *a;
    *a = *b;
    *b = t;

    int tmp = (*a)->idx;
    (*a)->idx = (*b)->idx;
    (*b)->idx = tmp;
}

void heapifyup(struct maxheap* h, int i) {
    if (i == 0) return;
    int p = (i - 1) / 2;
    if (h->arr[p]->freq < h->arr[i]->freq) {
        swap(&h->arr[p], &h->arr[i]);
        heapifyup(h, p);
    }
}

void heapifydown(struct maxheap* h, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < h->len && h->arr[l]->freq > h->arr[largest]->freq)
        largest = l;
    if (r < h->len && h->arr[r]->freq > h->arr[largest]->freq)
        largest = r;

    if (largest != i) {
        swap(&h->arr[i], &h->arr[largest]);
        heapifydown(h, largest);
    }
}

void insert(struct maxheap* h, struct node* n) {
    h->arr = realloc(h->arr, sizeof(struct node*) * (h->len + 1));
    h->arr[h->len] = n;
    n->idx = h->len;
    heapifyup(h, h->len);
    h->len++;
}

struct node* pop(struct maxheap* h) {
    struct node* top = h->arr[0];
    h->arr[0] = h->arr[h->len - 1];
    h->arr[0]->idx = 0;
    h->len--;
    heapifydown(h, 0);
    return top;
}

/* ================= SOLUTION ================= */

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    struct mnode** hash = calloc(MAP_LEN, sizeof(struct mnode*));
    struct maxheap* heap = createmaxheap();

    for (int i = 0; i < numsSize; i++) {
        int idx = gethash(nums[i]);
        struct mnode* cur = hash[idx];

        while (cur && cur->key != nums[i])
            cur = cur->next;

        if (!cur) {
            struct node* n = createnode(nums[i]);
            insert(heap, n);

            struct mnode* mn = malloc(sizeof(struct mnode));
            mn->key = nums[i];
            mn->hptr = n;
            mn->next = hash[idx];
            hash[idx] = mn;
        } else {
            cur->hptr->freq++;
            heapifyup(heap, cur->hptr->idx);
        }
    }

    int* ans = malloc(sizeof(int) * k);
    *returnSize = k;

    for (int i = 0; i < k; i++)
        ans[i] = pop(heap)->val;

    return ans;
}
