// ============================================================
// Program 03b: Pointer Dasar
// Deskripsi : Memperkenalkan konsep pointer - variabel yang
//             menyimpan alamat memori variabel lain.
// Konsep    : - Pointer: variabel yang berisi alamat, bukan nilai
//             - int *ptr = &battery: ptr menyimpan alamat battery
//             - *ptr (dereference): mengakses nilai di alamat tsb
//             - Dengan pointer, kita bisa mengubah nilai variabel
//               asli secara tidak langsung
// ============================================================

#include <iostream>

int main()
{
    int battery = 100;

    // Tampilkan nilai dan alamat battery
    std::cout << "battery : " << battery << '\n';
    std::cout << "&battery : " << &battery << '\n';

    // Deklarasi pointer yang menunjuk ke alamat battery
    int *ptr = &battery;

    // ptr berisi alamat, *ptr berisi nilai di alamat tersebut
    std::cout << "ptr : " << ptr << '\n';
    std::cout << "*ptr : " << *ptr << '\n';

    // Ubah nilai battery melalui pointer (dereference)
    *ptr = 50;

    // Nilai battery berubah karena *ptr mengakses memori yang sama
    std::cout << battery << '\n';

    return 0;
}
