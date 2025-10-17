//Stack dengan linkedlist
#include <iostream>
using namespace std;

struct dataBarang{
    string namabarang ;
    int hargaBarang ;

    dataBarang *prev;
    dataBarang *next;
};

dataBarang *head , *tail , *current , *newNode , *del ;

int penuh = 5 ;

void createNewStack(string namabarang , int hargabarang){
    head = new dataBarang();
    head->namabarang = namabarang;
    head->hargaBarang = hargabarang;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

int countBarang(){
    if (head == NULL){
        return 0;
    }else{
        current = head;
        int banyak = 0;
        while(current != NULL){
            current = current->next;
            banyak++;
        }
        return banyak;
    }
}

bool isEmpty(){
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    if (countBarang() == penuh){
        return true ;
    }else {
        return false ;
    }
}

void pushBarang(string namabarang , int hargabarang){
    if (isFull()){

        cout << "\nUser Mencoba Memasukan Data di Stack" << endl;
        cout << "Status : Stack Barang Full" << endl;
        
    }else{
        if (isEmpty()){
            createNewStack(namabarang , hargabarang);
        }else {
            newNode = new dataBarang();
            newNode->namabarang = namabarang;
            newNode->hargaBarang = hargabarang;
            newNode->prev = tail;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void popBarang(){
    if (tail == head){
        delete head;
        head = NULL;
    }else{
        del = tail;
        tail = tail->prev;
        tail->next == NULL;
        delete del;
}
    
}

void displayBarang(){
    if (isEmpty()){
        cout << "Stack Kosong" << endl ;

    }else {
        current = tail ;
        cout << "==== Stack Barang ===="<< endl;
        while (current != NULL){
            cout << "Nama Barang \t: " << current->namabarang << endl;
            cout << "Harga Barang \t: "<< "Rp." << current->hargaBarang << endl;
            cout << "======================" <<endl;
            current = current->prev;

        }
    }
}

void destroyStack(){
    current = head ;
    while(current != NULL){
        del = current ;
        head = head->next;
        delete del;
        current = current->next;
    }
}

int main(){

        pushBarang("Payung",10000);
        pushBarang("Iphone",70000);
        pushBarang("Sempak",120000);
        pushBarang("Kecap",467000);
        // pushBarang("Kertas",1200);
        // pushBarang("test",2000);

        //popBarang();
        destroyStack();
        displayBarang();
    
}