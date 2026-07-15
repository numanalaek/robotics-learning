// ============================================================
// Program 05b: Pass by Value (Efisien dengan const Reference)
// Deskripsi : Menggunakan const reference agar data besar tidak
//             di-copy, tetapi juga tidak bisa dimodifikasi.
// Konsep    : - const std::string &name = reference read-only
//             - Tidak ada penyalinan data (lebih cepat)
//             - Data asli terlindungi (const)
//             - Ini adalah cara terbaik untuk parameter baca-saja
// ============================================================

#include <iostream>
#include <string>

// const reference: baca data tanpa copy, tanpa bisa ubah asli
void printName(const std::string &name)
{
    std::cout << "Robot : " << name << '\n';
    // name = "xxx"; // ERROR: const reference tidak bisa diubah
}

int main()
{
    std::string robot = "NUIN-AMR-01";

    printName(robot);

    std::cout << "Di main : " << robot << '\n';

    return 0;
}
