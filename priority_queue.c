#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

PriorityQueue* create_queue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if (!pq) return NULL; /* Bellek hatasý kontrolü */
    pq->heap = (Request*)malloc(sizeof(Request) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap_requests(Request* a, Request* b) {
    Request temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify Up: Yeni eleman eklenince yapýyý korur */
void push(PriorityQueue* pq, Request req) {
    if (pq->size == pq->capacity) return;

    pq->heap[pq->size] = req;
    int curr = pq->size;
    pq->size++;

    /* Min-Heap: Küçük öncelik deðeri yukarý çýkar */
    while (curr > 0 && pq->heap[curr].priority < pq->heap[(curr - 1) / 2].priority) {
        swap_requests(&pq->heap[curr], &pq->heap[(curr - 1) / 2]);
        curr = (curr - 1) / 2;
    }
}

/* Heapify Down: Eleman çekilince yapýyý korur */
Request pop(PriorityQueue* pq) {
    Request root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];

    int curr = 0;
    while (2 * curr + 1 < pq->size) {
        int smallest = 2 * curr + 1;
        int right = 2 * curr + 2;

        if (right < pq->size && pq->heap[right].priority < pq->heap[smallest].priority)
            smallest = right;

        if (pq->heap[curr].priority <= pq->heap[smallest].priority) break;

        swap_requests(&pq->heap[curr], &pq->heap[smallest]);
        curr = smallest;
    }
    return root;
}

/* Bellek Temizliði */
void free_queue(PriorityQueue* pq) {
    free(pq->heap);
    free(pq);
}
