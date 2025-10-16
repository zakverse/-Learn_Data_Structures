#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    

    string nama = "DZAKI KHOTHIR";

    for( int i = 0 ; i < nama.length() ; i++ ){
        nama[i] = tolower(nama[i]);
    }

    cout << nama ;

}