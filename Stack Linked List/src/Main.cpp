#include <iostream>

#define MAX 5

using namespace std;

struct Mahasiswa{
    string nama;
    int umur;
    Mahasiswa *sesudah, *sebelum;
};

Mahasiswa *kepala, *ekor, *bantu, *nodeBaru, *hapusNode;

void buatMhs( string nama, int umur ){
    kepala = new Mahasiswa();
    kepala->nama = nama;
    kepala->umur = umur;
    kepala->sebelum = NULL;
    kepala->sesudah = NULL;
    ekor = kepala;
}

int hitungMhs(){
    if( kepala == NULL ){
        return 0;
    } else {
        int jumlah = 0;
        bantu = kepala;
        while ( bantu != NULL ){
            bantu = bantu->sesudah;
            jumlah++;
        }
        return jumlah;
    }
}

bool penuhMhs(){
    if( hitungMhs() == MAX ){
        return true;
    } else {
        return false;
    }
}

bool kosongMhs(){
    if( hitungMhs() == 0 ){
        return true;
    } else {
        return false;
    }
}

void tambahMhs( string nama, int umur ){
    if( penuhMhs() ){
        cout << "Stack FULL!!!" << endl;
    } else {
        if( kosongMhs() ){
            buatMhs( nama, umur );
        } else {
            nodeBaru = new Mahasiswa();
            nodeBaru->nama = nama;
            nodeBaru->umur = umur;
            nodeBaru->sebelum = ekor;
            ekor->sesudah = nodeBaru;
            nodeBaru->sesudah = NULL;
            ekor = nodeBaru;
        }
    }
}

void hapusMhs(){
    hapusNode = ekor;
    ekor = ekor->sebelum;
    ekor->sesudah = NULL;
    delete hapusNode;
}

void ubahMhs( string nama, int umur, int posisi ){
    if( kosongMhs() ){
        cout << "Stack Kosong" << endl;
    } else {
        int nomor = 1;
        bantu = ekor;
        while ( nomor < posisi ){
            bantu = bantu->sebelum;
            nomor++;
        }
        bantu->nama = nama;
        bantu->umur = umur;
    }
}

void cetakMhs(){
    if( kosongMhs() ){
        cout << "Stack Kosong" << endl;
    } else {
        cout << "=====Data Mahasiswa=====" << endl; 
        bantu = ekor;
        while ( bantu != NULL ){
            cout << "Nama\t: " << bantu->nama << endl;
            cout << "Umur\t: " << bantu->umur << endl;
            cout << "------------------------" << endl;
            bantu = bantu->sebelum;
        }
        cout << "========================" << endl;
    }
}

void lihatMhs( int posisi ){
    if( kosongMhs() ){
        cout << "Stack Kosong" << endl;
    } else {
        int nomor = 1;
        bantu = ekor;
        while ( nomor < posisi ){
            bantu = bantu->sebelum;
            nomor++;
        }
        cout << "Data ke-" << posisi << endl;
        cout << "Nama\t: " << bantu->nama << endl;
        cout << "Umur\t: " << bantu->umur << endl;
    }
}

void hapusSemua(){
    bantu = kepala;
    while ( bantu != NULL ){
        hapusNode = bantu;
        kepala = kepala->sesudah;
        delete bantu;
        bantu = bantu->sesudah;
    }
    
}

int main(){

    tambahMhs("Ikhwan Fi'la",21);
    tambahMhs("Fara Darniva",20);
    tambahMhs("Retha Faradina",18);
    tambahMhs("Luthfi Miftah",19);
    tambahMhs("Della Erinda",22);
    cetakMhs();
    lihatMhs(4);
    ubahMhs("Irgi Saputra",20,3);
    cetakMhs();
    return 0;

}