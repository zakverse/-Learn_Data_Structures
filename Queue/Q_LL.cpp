#include <iostream>
using namespace std;

struct QueuePelanggan {
    string namaPelanggan ;

    QueuePelanggan *next;
};

QueuePelanggan *head , *tail , *current ,*del , *newNode;
const int Maksimal = 5;

int countQueue(){
    if (head == NULL){
        return 0;
    }else{
        int banyak = 0;
        current = head;
        while (current != NULL){
            current = current->next;
            banyak++ ;
        }
        return banyak;
        
    }
}

bool isFull(){
    return countQueue() == Maksimal;
}

bool isEmpty(){
    return countQueue() == 0 ;
}

//  delete
void dequeue(){
    if (isEmpty()){
        cout << "Antrian Kosong" << endl;
    }else{
        del = head;
        head = head->next;
        delete del;
    }
}

//  add
void enqueue(string nama){
    if (isFull()){
        cout << "=====WARNING=====" << endl;
        cout << "  Antrian Penuh  " << endl;
        cout << "=================" << endl;
    }else{
        
        if(isEmpty()){
            head = new QueuePelanggan();
            head->namaPelanggan = nama;
            head->next = NULL;
            tail = head;
        }else{
            newNode = new QueuePelanggan();
            newNode->namaPelanggan = nama;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
            
        }
    }
}

void printQueue(){
    cout << "Data Antrian : " << endl;
    if(isEmpty()){
        cout << " Antrian Kosong " << endl;
    }else{
        current = head;
        int nomor = 1;
        while(nomor <= Maksimal){
            if (current != NULL){
                cout << nomor << ". " << current->namaPelanggan << endl;
                current = current->next;
            }else{
                cout << nomor << ". " << "(Kosong)" << endl;
            }
            nomor++;
        }
    }
}

void destroy(){
    if (isEmpty()){
        cout << "Data Kosong"<< endl;
    }else{
        current = head;
        while(current != NULL){
            del = current;
            delete del;
            current = current->next;
        }
        head = NULL;
        tail = NULL;
    }
}


int main(){

    enqueue("Boboiboy");
    enqueue("Yaya");
    enqueue("Ying");
    enqueue("Gopal");
    dequeue();
   // enqueue("Fang");
   // enqueue("Adudu");
   destroy();
    printQueue();
    cout << "\nBanyak Data : " << countQueue() << endl;
}  