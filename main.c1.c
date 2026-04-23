#include <stdio.h>
#include "priority_queue.h"
#include "rfc_parser.h"

int main() {
    /* 1. Kuyruðu oluþtur (Bellek yönetimi) */
    PriorityQueue* pq = create_queue(10);

    /* 2. Test Senaryosu: Karýþýk sýralarda istekler geliyor */
    Request r1 = {101, parse_rfc_priority("u=5"), "/api/data"};
    Request r2 = {102, parse_rfc_priority("u=1"), "/api/login"};
    Request r3 = {103, parse_rfc_priority("u=0"), "/api/admin"};

    printf("--- Ýstekler Kuyruða Ekleniyor ---\n");
    push(pq, r1); printf("Eklendi: ID %d (u=5)\n", r1.id);
    push(pq, r2); printf("Eklendi: ID %d (u=1)\n", r2.id);
    push(pq, r3); printf("Eklendi: ID %d (u=0)\n", r3.id);

    printf("\n--- Öncelik Sýrasýna Göre Ýþleniyor (Min-Heap) ---\n");
    while (pq->size > 0) {
        Request current = pop(pq);
        printf("Islem Yapiliyor -> ID: %d, Oncelik Seviyesi: %d, Endpoint: %s\n", 
                current.id, current.priority, current.endpoint);
    }

    /* 3. Belleði Serbest Býrak (Sýfýr bellek sýzýntýsý kriteri) */
    free_queue(pq);
    
    printf("\nSistem basariyla kapatildi.\n");
    return 0;
}
