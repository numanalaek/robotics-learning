// ============================================================
// Program 05g: Const Reference
// Deskripsi : Menggunakan const reference untuk parameter yang
//             hanya perlu dibaca (read-only), tidak diubah.
// Konsep    : - const reference: tidak bisa mengubah data asli
//             - Lebih aman karena mencegah modifikasi tak sengaja
//             - Tetap efisien karena tidak ada penyalinan
//             - Best practice: gunakan const reference untuk
//               parameter objek besar yang hanya perlu dibaca
// ============================================================

#include <iostream>
#include <string>

// const reference: baca saja, tidak bisa diubah
void printName(const std::string &name)
{
    std::cout << "Alamat di fungsi : " << &name << '\n';
    std::cout << "Isi di fungsi    : " << name << '\n';

    // name = "MODIFIED";  // ERROR: const reference tidak bisa diubah
}

int main()
{
    std::string robot = "NUIN-AMR-01";

    std::cout << "Alamat di main   : " << &robot << '\n';
    std::cout << "Isi di main      : " << robot << '\n';

    printName(robot);

    // robot tetap "NUIN-AMR-01" karena const reference tidak bisa ubah
    std::cout << "Isi di main setelah fungsi : " << robot << '\n';

    return 0;
}
