#include <iostream>

using namespace std;

int main(){

    // Mencetak alamat pada variable
    string nama = "Ikhwan Fi'la Wadzakiiya";
    cout << nama << " berada pada alamat\t: " << &nama << endl;

    // Mendeklarasi Variable Pointer
    string *pointerNama = &nama;
    cout << "Pointer Nama\t\t\t\t\t: " << pointerNama << endl;

    // Mencetak nilai pada variable pointer
    cout << "Nilai pada pointer nama\t\t\t\t: " << *pointerNama << endl;

    // Manipulasi nilai
    *pointerNama = "Fara Darniva";
    cout << "Nilai pada pointer nama\t\t\t\t: " << *pointerNama << endl;

    return 0;
    
}