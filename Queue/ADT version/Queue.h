#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

// ===== STRUCT & TYPEDEF =====
struct Pelanggan {
    string namaPelanggan;
};
typedef Pelanggan dataPelanggan;
typedef struct ElemenQueue *address;

struct ElemenQueue {
    dataPelanggan info;
    address next;
};

struct Queue {
    address head;
    address tail;
    int kapasitas;
    int size;
};

// ===== FUNGSI =====
Queue CreateQueue(int max);
bool IsEmpty(Queue q);
bool IsFull(Queue q);
void Enqueue(Queue &q, string nama);
void Dequeue(Queue &q);
void PrintQueue(Queue q);
void DestroyQueue(Queue &q);

#endif
