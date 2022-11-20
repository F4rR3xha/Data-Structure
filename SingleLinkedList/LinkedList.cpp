#include <iostream>

using namespace std;

// Deklarasi Single Linked List
struct Mahasiswa{
    
    // Variable
    string nama, nim;
    int umur;

    Mahasiswa *selanjutnya;

};

Mahasiswa *kepala, *ekor, *arus, *nodeBaru, *hapusNode, *nodeBantu;

void buatSLL( string nama, string nim, int umur ) {
    kepala = new Mahasiswa();
    kepala->nama = nama;
    kepala->nim = nim;
    kepala->umur = umur;
    kepala->selanjutnya = NULL;
    ekor = kepala;
}

int jumlahSLL(){
    arus = kepala;
    int jumlah = 0;
    while ( arus != NULL ){
        jumlah++;
        arus = arus->selanjutnya;
    }
    return jumlah;
}

void tambahAwalSLL( string nama, string nim, int umur ){
    nodeBaru = new Mahasiswa();
    nodeBaru->nama = nama;
    nodeBaru->nim = nim;
    nodeBaru->umur = umur;
    nodeBaru->selanjutnya = kepala;
    kepala = nodeBaru;
}

void tambahTengahSLL( string nama, string nim, int umur, int posisi ){
    if( posisi < 1 || posisi > jumlahSLL() ){
        cout << "Posisi di luar jangkauan" << endl;
    } else if( posisi == 1 ){
        cout << "Bukan posisi tengah" << endl;
    } else {
        nodeBaru = new Mahasiswa();
        nodeBaru->nama = nama;
        nodeBaru->nim = nim;
        nodeBaru->umur = umur;
        arus = kepala;
        int nomor = 1;
        while( nomor < posisi-1 ){
            arus = arus->selanjutnya;
            nomor++;
        }
        nodeBaru->selanjutnya = arus->selanjutnya;
        arus->selanjutnya = nodeBaru;
    }
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

void ubahTengahSLL( string nama, string nim, int umur, int posisi ){
    if( posisi < 1 || posisi > jumlahSLL() ){
        cout << "Posisi di luar jangkauan" << endl;
    } else if( posisi == 1 || posisi == jumlahSLL() ){
        cout << "Bukan posisi tengah" << endl;
    } else {
        arus = kepala;
        int nomor = 1;
        while( nomor < posisi ){
            arus = arus->selanjutnya;
            nomor++;
        }
        arus->nama = nama;
        arus->nim = nim;
        arus->umur = umur;
    }
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

void hapusTengahSLL( int posisi ){
    if( posisi < 1 || posisi > jumlahSLL() ){
        cout << "Posisi di luar jangkauan" << endl;
    } else if( posisi == 1 || posisi == jumlahSLL() ){
        cout << "Bukan posisi tengah" << endl;
    } else {
        int nomor = 1;
        arus = kepala;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                nodeBantu = arus;
            } if ( nomor == posisi ){
                hapusNode = arus;
            }
            arus = arus->selanjutnya;
            nomor++;
        }
        nodeBantu->selanjutnya = arus;
        delete hapusNode;
    }
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
    cout << "Jumlah Data Ada : " << jumlahSLL() << endl;
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
    ubahAwalSLL( "Ikhwan Fi'la Wadzakiyya","A11.2001.1010",21 );
    ubahAkhirSLL( "Luthfi Miftah Mumtaz","A11.2002.2205",20 );
    cetakSLL();
    tambahTengahSLL( "Fara Darniva","A11.2002.0107",20,2 );
    tambahTengahSLL( "Retha Faradina Mecka","A11.2003.3008",18,3 );
    cetakSLL();
    hapusTengahSLL(3);
    cetakSLL();
    ubahTengahSLL( "Retha Faradina Mecka","A11.2003.3008",18,2 );
    cetakSLL();

}