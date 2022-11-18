#include <iostream>
#define max 5

using namespace std;

string arrayNama[max];
int top = 0;

bool apakahPenuh(){
    if( top == max ){
        return true;
    } else {
        return false;
    }
}

bool apakahKosong(){
    if( top == 0 ){
        return true;
    } else {
        return false;
    }
}

void masukanArray( string nama ){
    if( apakahPenuh() ){
        cout << "Stack Penuh" << endl;
    } else {
        arrayNama[top] = nama;
        top++;
    }
}

void keluarkanArray(){
    if( apakahKosong() ){
        cout << "Stack Kosong" << endl;
    } else {
        top--;
    }
}

int menghitungStack(){
    if( apakahKosong() ){
        return 0;
    } else {
        return top;
    }
}

void ubahArray( string nama, int posisi ){
    if( apakahKosong() ){
        cout << "Stack Kosong" << endl;
    } else {
        int index = top;
        for( int i=0; i<posisi; i++ ){
            index--;
        }
        arrayNama[index] = nama;
    }
}

void melihatArray( int posisi ){
    if( apakahKosong() ){
        cout << "Stack Kosong" << endl;
    } else {
        int index = top;
        for( int i=0; i<posisi; i++ ){
            index--;
        }
        cout << "Nama dari posisi ke-" << posisi << " adalah " << arrayNama[index] << endl;
    }
}

void cetakStack(){
    if( apakahKosong() ){
        cout << "Stack Kosong" << endl;
    } else {
        cout << "===================================" << endl;
        cout << "Data Stack Array" << endl;
        for( int i=max-1; i>=0; i-- ){
            if( arrayNama[i] != "" ){
                cout << "Nama\t: " << arrayNama[i] << endl;
            }
        }
        cout << "===================================" << endl;
    }
}

void menghapusArray(){
    for( int i=0; i<top; i++ ){
        arrayNama[i] = "";
    }
    top = 0;
}

int main(){

    cetakStack();
    masukanArray("Ikhwan Fi'la");
    masukanArray("Fara Darniva");
    masukanArray("Retha Faradhina");
    cetakStack();
    melihatArray(3);
    cout << "Banyak Stack : " << menghitungStack() << endl;
    ubahArray("Luthfi Miftah",3);
    cetakStack();
    menghapusArray();
    cetakStack();
    masukanArray("Ikhwan Fi'la");
    masukanArray("Fara Darniva");
    cetakStack();

}