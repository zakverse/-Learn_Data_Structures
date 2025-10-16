#include <iostream>
using namespace std;

const int penuh = 5 ;
string arrBuku[penuh];
int top = 0;

bool isFull(){
    if(top == penuh){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(){
    if(top == 0){
        return true;
    }else{
        return false;
    }
}

void pushArray(string data){
    if (isFull()){
        cout << "Data Penuh" << endl;
    }else{
        arrBuku[top] = data;
        top++;
    }
}

void popArray(){
    if (isEmpty()){
        cout << "Data Kosong " << endl;
    }else{
        arrBuku[top - 1] = "";
        top--;
    }
}

void displayArray(){
    if (isEmpty){
        cout << "Data kosong" << endl;
    }else{
        cout << "==== Data Stack Array ==== " << endl;
    for(int i = penuh - 1 ; i >= 0 ; i--){
        if( arrBuku[i]!= ""){
            cout << "Data \t: " << arrBuku[i] << endl;
        }
    }
    cout << "==========================" << endl ;
    }
}

void peekArray(int posisi){
    if (isEmpty()){
        cout << "Data nya kosong cok"<< endl;
    }else{
        int index = top;
        for(int i = 0 ; i < posisi ; i++){
            index--;
        }
        cout << "Data Posisi ke - " << posisi << " : " << arrBuku[index] << endl;
    }
}

int countArray(){
    if (isEmpty()){
        return 0;
    }else{
        return top;
    }
}

void destroyStack(){
    for ( int i = 0 ; i < top ; i++ ){
        arrBuku[i] = "";
    }
    top = 0 ;
}

int main(){
   pushArray("Legend Of Ngawi City");
   pushArray("Ambatron dan rusdi");
   pushArray("How to hair styling by rusdi");
   pushArray("Buku Horor Ambacong");
   pushArray("Legenda Sungai Muani");
   //pushArray("Learn cook with Mas fuad");
   //popArray();
   //peekArray(3);
   //displayArray();

   cout << "Banyak Data : " << countArray() << endl;


//    if (isFull()){
//     cout << "Apakah Stack penuh ? : udah penuh cok" << endl;
//    }else{
//     cout << "Apakah Stack penuh ? : masih bisa ini mah" << endl;
//    }
   

}
