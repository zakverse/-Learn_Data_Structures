#include <iostream>
using namespace std;


//Deklarasi Double LikedList
struct Datauser{
    string nama, username, email, password;

    Datauser *prev;
    Datauser *next; 
};

Datauser *head , *tail, *del, *current, *newNode , *afterNode ;

void NewDoubleLinkedList(string nama , string username , string email, string password){
    head = new Datauser();
     
    head->nama = nama ;
    head->username = username;
    head->email = email;
    head->password = password;
    head->prev = NULL;
    head->next = NULL;

    tail = head;

}

int CountNode(){
    current = head;
    int lenght = 0;
    while(current != NULL){
        current = current->next;
        lenght++;
    }
    return lenght;
}

void AddFirst(string nama , string username , string email, string password){

    if (head == NULL){
    cout << "Belum ada data";
    }else{
    newNode = new Datauser();
     
    newNode->nama = nama ;
    newNode->username = username;
    newNode->email = email;
    newNode->password = password;
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode; 

    head = newNode;
    }
}



void AddLAst(string nama , string username , string email, string password){

    if (head == NULL){
    cout << "Belum ada data";
    }else{
    newNode = new Datauser();
     
    newNode->nama = nama ;
    newNode->username = username;
    newNode->email = email;
    newNode->password = password;
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
   
    tail = newNode;
    }
}

void AddMiddle(string nama , string username , string email, string password ,int position){

    if (position == 1){
        AddFirst(nama , username ,email ,password);
        return;
    }

    if (position == CountNode()){
        AddLAst(nama , username ,email ,password);
        return;
    }

    if (head == NULL){
    cout << "Belum ada data";
    }else{
    newNode = new Datauser();
     
    newNode->nama = nama ;
    newNode->username = username;
    newNode->email = email;
    newNode->password = password;

    //Transversing
    current = head ;
    int nomor = 1;
    while ( nomor < position - 1){

        current = current->next;
        nomor++;
    }

    afterNode = current->next;
    newNode->prev = current;
    newNode->next = afterNode;
    current->next = newNode;
    afterNode->prev = newNode;
    
    }

}


void DeleteFirst(){

    if (head == NULL){
    cout << "Belum ada data";
    }else{
      del = head ;
      head = head->next;
      head->prev = NULL;
      delete del;
    }

}


void DeleteLast(){

    if (head == NULL){
    cout << "Belum ada data";
    }else{
      del = tail ;
      tail = tail->prev;
      tail->next = NULL;
      delete del;
    }
}

void DeleteMiddle(int Position){

     if (Position == 1){
        DeleteFirst();
        return;
    }

    if (Position == CountNode()){
        DeleteLast();
        return;
    }


    if (head == NULL){
    cout << "Belum ada data";
    }else{
    current = head ;
    int nomor = 1;
    while ( nomor < Position - 1){

        current = current->next;
        nomor++;
    }
    del = current->next;
    afterNode = current->next->next;
    current->next = afterNode;
    afterNode->prev = current;

    delete del;

    }

}

void PrintDLL(){
  if (head == NULL){
    cout << "Belum ada data";
  }else{
      current = head ;
    while( current != NULL ){
        cout << "Nama \t\t: " << current->nama << endl;
        cout << "Username \t: " << current->username << endl;
        cout << "Email \t\t: " << current->email << endl;
        cout << "Password \t: " << current->password << endl;
        cout << endl;

        current = current->next;
    }

  }
}

int main(){

    NewDoubleLinkedList("Rusdi", "Rusdi Barber" ,"Rusdibarber@Ngawi.com" , "ADUHH GANTENGNYAAA");
    AddFirst("AmbaTukam", "Muani Hunter", "ambasing@ngawi.com","popmipopmi");
    AddLAst("Mr.Ironi" , "Miaw" ,"ironi@ngawi.com","muach123");
    AddMiddle("Andre", "Andriana","andre@ngawi.com","Aduh Ganteng nyaaa", 2);
    //DeleteFirst();
    //DeleteLast();
    DeleteMiddle(4);

    
    PrintDLL();

}