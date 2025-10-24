#include "Queue.h"

Queue CreateQueue(int max) {
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.kapasitas = max;
    q.size = 0;
    return q;
}

bool IsEmpty(Queue q) {
    return q.size == 0;
}

bool IsFull(Queue q) {
    return q.size == q.kapasitas;
}

void Enqueue(Queue &q, string nama) {
    if (IsFull(q)) {
        cout << "=====WARNING=====" << endl;
        cout << "  Antrian Penuh  " << endl;
        cout << "=================" << endl;
        return;
    }

    address newNode = new ElemenQueue;
    newNode->info.namaPelanggan = nama;
    newNode->next = NULL;

    if (IsEmpty(q)) {
        q.head = newNode;
        q.tail = newNode;
    } else {
        q.tail->next = newNode;
        q.tail = newNode;
    }
    q.size++;
}

void Dequeue(Queue &q) {
    if (IsEmpty(q)) {
        cout << "Antrian Kosong" << endl;
        return;
    }

    address del = q.head;
    q.head = q.head->next;
    delete del;
    q.size--;

    if (q.head == NULL)
        q.tail = NULL;
}

void PrintQueue(Queue q) {
    cout << "Data Antrian:" << endl;
    if (IsEmpty(q)) {
        cout << " Antrian Kosong" << endl;
        return;
    }

    address current = q.head;
    int nomor = 1;
    while (nomor <= q.kapasitas) {
        if (current != NULL) {
            cout << nomor << ". " << current->info.namaPelanggan << endl;
            current = current->next;
        } else {
            cout << nomor << ". (Kosong)" << endl;
        }
        nomor++;
    }
}

void DestroyQueue(Queue &q) {
    while (!IsEmpty(q)) {
        Dequeue(q);
    }
    cout << "Semua data telah dihapus." << endl;
}
