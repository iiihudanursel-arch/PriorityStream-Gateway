#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

/* RFC 9213'e uygun Ýstek Yapýsý */
typedef struct {
    int id;               /* Ýstek ID'si */
    int priority;         /* RFC 9213: 0 (En Yüksek) - 7 (En Düþük) */
    char endpoint[100];   /* Ýstek adresi (örn: /api/login) */
} Request;

/* Min-Heap tabanlý Öncelikli Kuyruk Yapýsý */
typedef struct {
    Request* heap;        /* Dinamik dizi (malloc ile ayrýlacak) */
    int size;             /* Mevcut eleman sayýsý */
    int capacity;         /* Maksimum kapasite */
} PriorityQueue;

/* Fonksiyon Ýmzalarý (Prototipleri) */
PriorityQueue* create_queue(int capacity);
void push(PriorityQueue* pq, Request req);
Request pop(PriorityQueue* pq);
void free_queue(PriorityQueue* pq);

#endif
