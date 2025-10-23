#include <iostream>
using namespace std;

//Variabel Global
const int  maksimal = 5 ;
int front = 0 ;
int back = 0 ;
string AntrianAtm[maksimal];

bool isFull(){
    return back == maksimal;
}

bool isEmpty(){
    return (back == 0) ;
}

// enqueue / Penambahan Antrian
void enqueueArray(string data){
    if (isFull()){
        cout << "== Antrian Penuh ==" << endl;
    }else{
        //Apakah kosong?
        if(isEmpty()){
            AntrianAtm[0] = data;
            front++;
            back++;
        }else{
            AntrianAtm[back] = data;
            back++;
        }
    }
}


void PrintQ(){
    if (isEmpty()){
        cout << "Antrian Kosong" << endl;
    }else{
        cout << "Data Antrian Atm : " << endl;
        for(int i = 0 ; i < maksimal ; i++){
            if(AntrianAtm[i] != ""){
                cout << i+1 << ". " << AntrianAtm[i] << endl;
            }else{
                cout << i+1 << ". (Kosong)" << endl;
            }
        }
    }

}

//Dequeue / Pengahapusan data depan
void dequeueArray(){
    
    if(isEmpty()){
        cout << "Antrian Kosong" << endl;
    }else{
       for (int i = 0 ; i < back ; i++){
        AntrianAtm[i] = AntrianAtm[i+1];
        
       }
       AntrianAtm[back-1]= "";
       back--;
    }
}

//menghitung banyak yang ngantri
int countArray(){
    if(isEmpty()){
        return 0;
    }else if(isFull()){
        return maksimal;
    }else{
        return back;
    }
}

void DestroyArray(){
    for(int i = 0 ; i < maksimal ; i++){
        AntrianAtm[i] = "";
        back--;
    }
    front = 0;
    back = 0;
}

int main(){

    enqueueArray("ironi");
    enqueueArray("Amba");
    enqueueArray("Rusdi");
    enqueueArray("Fuad");
    enqueueArray("Andre");
    //enqueueArray("Narji");
    //dequeueArray();
    DestroyArray();
    PrintQ();

    cout << "Jumlah Antrean : "<< countArray() << endl;
}