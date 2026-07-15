// ============================================================
// Program 03a: Memori dan Alamat
// Deskripsi : Menampilkan nilai variabel beserta alamat memori
//             tempat variabel disimpan.
// Konsep    : - Setiap variabel punya alamat unik di memori
//             - Operator & mengambil alamat variabel
//             - static_cast<void*> diperlukan untuk char karena
//               cout akan menafsirkan char* sebagai string
//             - Alamat memori ditampilkan dalam format heksadesimal
// ============================================================

#include <iostream>

int main()
{
    // Deklarasi variabel dengan tipe berbeda
    int battery = 100;     // int: 4 byte
    double voltage = 24.6; // double: 8 byte
    char command = 'W';    // char: 1 byte

    // Cetak NILAI dari setiap variabel
    std::cout << "battery : " << battery << '\n';
    std::cout << "voltage : " << voltage << '\n';
    std::cout << "command : " << command << '\n';

    // Cetak ALAMAT MEMORI dari setiap variabel
    // Operator & mengembalikan alamat di mana variabel disimpan
    std::cout << "\nAddress\n";

    std::cout << "battery : " << &battery << '\n';
    std::cout << "voltage : " << &voltage << '\n';
    // static_cast<void*> diperlukan agar char* tidak dibaca sebagai string
    std::cout << "command : " << static_cast<void *>(&command) << '\n';

    return 0;
}
