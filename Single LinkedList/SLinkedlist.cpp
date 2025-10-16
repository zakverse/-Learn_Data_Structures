#include <iostream>
using namespace std;

// Deklarasi Single LinkedList
struct Buku{
//Komponen / Member
  string judul , pengarang ;
  int tahunTerbit;

  Buku *Next;
};

Buku *Head , *Tail , *Current, *NewNode, *Del, *Prev ;


// Membuat Single Linked List Awal
void NewSingleLikedList(string judul , string pengrang , int tahunTerbit){

    Head = new Buku();

    Head->judul = judul;
    Head->pengarang = pengrang;
    Head->tahunTerbit = tahunTerbit;
    Head->Next = NULL;

    Tail = Head;

}

int CountLenght(){
    Current = Head;

    int panjang = 0;
    while(Current != NULL){
        Current = Current->Next;
        panjang++;
    }

    return panjang;
}

void AppendDiAwal(string judul , string pengrang , int tahunTerbit){
    NewNode = new Buku();

    NewNode->judul = judul;
    NewNode->pengarang = pengrang;
    NewNode->tahunTerbit = tahunTerbit;
    NewNode->Next = Head;

    Head = NewNode;

    
}

void AppendDiAkhir(string judul , string pengrang , int tahunTerbit){
    NewNode = new Buku();

    NewNode->judul = judul;
    NewNode->pengarang = pengrang;
    NewNode->tahunTerbit = tahunTerbit;
    NewNode->Next = NULL;

    Tail->Next = NewNode;
    Tail = NewNode;
}

void ApppendDiTengah(string judul , string pengrang , int tahunTerbit , int posisi){
   
    NewNode = new Buku();
    NewNode->judul = judul;
    NewNode->pengarang = pengrang;
    NewNode->tahunTerbit = tahunTerbit;

    Current = Head;
    int nomor = 1;
    while( nomor < posisi -1){
        Current = Current->Next;
        nomor++;
    }
    NewNode->Next = Current->Next;
    Current->Next = NewNode;   
}



void DeleteAwal(){

    Del = Head;
    Head = Head->Next;
    delete Del;


}

void DeleteTengah(int posisi){
     if ( posisi < 1 || posisi > CountLenght() ){
            cout << "Posisi Diluar Jangkauan bro" << endl;
            return;
    }else if ( posisi == 1 || posisi == CountLenght() ){
            cout << "Bukan Posisi Tengah ini bro jangan pake fungsi ini hadeeh" << endl;
           return;
        }
    Current = Head ;
    int nomor = 1 ;
    while ( nomor <= posisi ){  
            if ( nomor == posisi-1 ) {
                Prev = Current;
        }
            if ( nomor == posisi ){
                Del = Current;
        }
            Current = Current->Next;
            nomor++;
        }
        Prev->Next = Current;
        delete Del ;                          
}

void DeleteAkhir(){
    if (Head == NULL) { // Menangani kasus jika list kosong
        cout << "List kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }
    if (Head == Tail) { // Menangani kasus jika hanya ada satu node
        delete Head;
        Head = NULL;
        Tail = NULL;
        return;
    }
    Del = Tail;
    Current = Head;
    while( Current->Next != Tail ){
        Current = Current->Next;    
    }
    Tail = Current;
    Tail->Next = NULL;
    delete Del;
}

void ChangeFirst(string judul , string pengrang , int tahunTerbit){
    Head->judul = judul;
    Head->pengarang = pengrang;
    Head->tahunTerbit = tahunTerbit;
}

void ChangeMiddle( string judul , string pengrang , int tahunTerbit , int posisi){
    if ( posisi < 1 || posisi > CountLenght() ){
            cout << "Posisi Diluar Jangkauan bro" << endl;
            return;
    }else if ( posisi == 1 || posisi == CountLenght() ){
            cout << "Bukan Posisi Tengah ini bro jangan pake fungsi ini hadeeh" << endl;
           return;
    }else{
        Current = Head;
        int nomor = 0;
        while ( nomor < posisi -1){
            Current = Current->Next;
            nomor++;
        }
        Current->judul = judul;
        Current->pengarang = pengrang;
        Current->tahunTerbit = tahunTerbit;
    }
   
}

void ChangeLast(string judul , string pengrang , int tahunTerbit){
    Tail->judul = judul;
    Tail->pengarang = pengrang;
    Tail->tahunTerbit = tahunTerbit;
}

void PrintSingleLikedList(){
    Current = Head;
    
    while(Current != NULL){
        cout << "Judul Buku \t: " << Current->judul << endl;
        cout << "Pengarang \t: " << Current->pengarang << endl;
        cout << "Tahun Terbit \t: " << Current->tahunTerbit << endl;
        cout << endl;

        Current = Current->Next;
    }

    cout << "Panjang Node : " << CountLenght() << endl;
}

int main(){
    
    NewSingleLikedList("Ini Buku Hitam", "LilNusNus" , 2024);
    AppendDiAwal("Petualangan Mas Rusdi" , "Amba", 1990);
    AppendDiAkhir("Kisah Horor Ambaruwo" , "mas faiz" , 1890);

    ApppendDiTengah("Ambatron Dan Rusdi" , "Si Ireng dari Ngawi" , 2024 , 3);

    // DeleteAwal();
    // DeleteAkhir();
    //DeleteTengah(9);

    //ChangeMiddle("Ambatron Dan Rusdi" , "Si Ireng dari Ngawi" , 9999 , 3);

    PrintSingleLikedList();

} 