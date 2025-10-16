#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 4, 7, 12, 15, 20}; 
    int n = 6; 
    int x ; 

    cout << "Array sebelum insert: ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Masukkan Nilai yang mau di sisip : ";
    cin >> x;

    // Cari posisi untuk menyisipkan x
    int pos = 0;
    while(pos < n && arr[pos] < x) {
        pos++;
    }

    // Geser elemen ke kanan
    for(int i=n; i>pos; i--){
        arr[i] = arr[i-1];
    }

    // Sisipkan elemen
    arr[pos] = x;
    n++;

    cout << "Array setelah insert: ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
