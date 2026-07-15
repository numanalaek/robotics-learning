// ============================================================
// Program 08b: Overloading - Gerak Robot
// Deskripsi : Fungsi move() di-overload untuk gerak tanpa
//             parameter (1 langkah) atau dengan jumlah langkah.
// Konsep    : - move()       : maju 1 langkah (default)
//             - move(int)    : maju n langkah
//             - Nama fungsi sama, parameter berbeda
// ============================================================

#include <iostream>

// Versi tanpa parameter: maju 1 langkah
void move()
{
    std::cout << "Robot maju 1 langkah\n";
}

// Versi dengan parameter: maju n langkah
void move(int step)
{
    std::cout << "Robot maju " << step << " langkah\n";
}

int main()
{
    move();     // Panggil versi tanpa parameter
    move(5);    // Panggil versi dengan parameter int
}
