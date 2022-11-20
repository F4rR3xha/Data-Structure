#include <iostream>

using namespace std;

// Deklarasi Single Linked List
struct Mahasiswa{
    
    // Variable
    string nama, nim;
    int umur;

    Mahasiswa *selanjutnya;

};

Mahasiswa *kepala, *ekor, *arus, *nodeBaru, *hapusNode;

void buatSLL( string nama, string nim, int umur ) {
    kepala = new Mahasiswa();
    kepala->nama = nama;
    kepala->nim = nim;
    kepala->umur = umur;
    kepala->selanjutnya = NULL;
    ekor = kepala;
}

void tambahAwalSLL( string nama, string nim, int umur ){
    nodeBaru = new Mahasiswa();
    nodeBaru->nama = nama;
    nodeBaru->nim = nim;
    nodeBaru->umur = umur;
    nodeBaru->selanjutnya = kepala;
    kepala = nodeBaru;
}

void tambahAkhirSLL( string nama, string nim, int umur ){
    nodeBaru = new Mahasiswa();
    nodeBaru->nama = nama;
    nodeBaru->nim = nim;
    nodeBaru->umur = umur;
    nodeBaru->selanjutnya = NULL;
    ekor->selanjutnya = nodeBaru;
    ekor = nodeBaru;
}

void ubahAwalSLL( string nama, string nim, int umur ){
    kepala->nama = nama;
    kepala->nim = nim;
    kepala->umur = umur;
}

void ubahAkhirSLL( string nama, string nim, int umur ){
    ekor->nama = nama;
    ekor->nim = nim;
    ekor->umur = umur;
}

void hapusAwalSLL(){
    hapusNode = kepala;
    kepala = kepala->selanjutnya;
    delete hapusNode;
}

void hapusAkhirSLL(){
    hapusNode = ekor;
    arus = kepala;
    while( arus->selanjutnya != ekor ){
        arus = arus->selanjutnya;
    }
    ekor = arus;
    ekor->selanjutnya = NULL;
    delete hapusNode;
}

void cetakSLL(){
    arus = kepala;
    while( arus != NULL ){
        cout << "==============================" << endl;
        cout << "Nama\t: " << arus->nama << endl;
        cout << "NIM\t: " << arus->nim << endl;
        cout << "Umur\t: " << arus->umur << endl;
        cout << "==============================" << endl;
        arus = arus->selanjutnya;
    }
    cout << endl;
}

int main(){

    buatSLL( "Ikhwan Fila","A11.12487",21 );
    cetakSLL();
    tambahAwalSLL( "Fara Darniva","A11.22086",20 );
    cetakSLL();
    tambahAkhirSLL( "Retha Faradina","A11.30081",19 );
    cetakSLL();
    hapusAwalSLL();
    cetakSLL();
    hapusAkhirSLL();
    cetakSLL();
    tambahAkhirSLL( "Luthfi Miftah","A11.22059",20 );
    cetakSLL();
    ubahAwalSLL( "Ikhwan Fi'la Wadzakiiya","A11.2001.1010",21 );
    ubahAkhirSLL( "Luthfi Miftah Mumtaz","A11.2002.2205",20 );
    cetakSLL();

}