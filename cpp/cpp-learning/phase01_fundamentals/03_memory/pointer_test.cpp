// ============================================================
// Program 03c: Pointer - Mengubah Nilai
// Deskripsi : Mendemonstrasikan bagaimana pointer digunakan
//             untuk mengubah nilai variabel beberapa kali.
// Konsep    : - Pointer ptr selalu menyimpan alamat yang sama
//             - *ptr = nilai_baru mengubah isi variabel asli
//             - battery, *ptr, dan &battery menunjukkan hubungan
//               antara variabel, pointer, dan alamat memori
// ============================================================

#include <iostream>

int main()
{
    int battery = 100;

    // Pointer ptr menunjuk ke alamat battery
    int *ptr = &battery;

    // Tampilkan kondisi awal
    std::cout << "battery : " << battery << '\n';
    std::cout << "ptr : " << ptr << '\n';
    std::cout << "*ptr : " << *ptr << '\n';
    std::cout << "&battery : " << &battery << '\n';

    // Ubah battery menjadi 50 melalui pointer
    std::cout << "\nChange the value of battery using pointer\n";
    *ptr = 50;

    std::cout << "battery : " << battery << '\n';
    std::cout << "ptr : " << ptr << '\n';
    std::cout << "*ptr : " << *ptr << '\n';
    std::cout << "&battery : " << &battery << '\n';

    // Ubah battery menjadi 80 melalui pointer
    std::cout << "\nChange the value of battery using pointer\n";
    *ptr = 80;

    std::cout << "battery : " << battery << '\n';
    std::cout << "ptr : " << ptr << '\n';
    std::cout << "*ptr : " << *ptr << '\n';
    std::cout << "&battery : " << &battery << '\n';

    return 0;
}
