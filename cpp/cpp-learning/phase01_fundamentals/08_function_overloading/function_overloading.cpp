// ============================================================
// Program 08a: Function Overloading
// Deskripsi : Mendemonstrasikan function overloading - beberapa
//             fungsi dengan NAMA SAMA tapi parameter BERBEDA.
// Konsep    : - C++ membedakan fungsi berdasarkan jumlah/jenis
//               parameter (bukan nama)
//             - printStatus() tanpa parameter
//             - printStatus(int) dengan 1 parameter
//             - printStatus(int, double) dengan 2 parameter
//             - Compiler memilih fungsi yang cocok otomatis
// ============================================================

#include <iostream>

// Versi 1: tanpa parameter
void printStatus()
{
    std::cout << "Robot READY\n";
}

// Versi 2: satu parameter int (battery)
void printStatus(int battery)
{
    std::cout << "Battery : " << battery << "%\n";
}

// Versi 3: dua parameter int dan double (battery, voltage)
void printStatus(int battery, double voltage)
{
    std::cout << "Battery : " << battery << "%\n";
    std::cout << "Voltage : " << voltage << " V\n";
}

int main()
{
    // Compiler memilih fungsi yang sesuai dengan argumen
    printStatus();           // Panggil versi 1 (tanpa parameter)
    printStatus(80);         // Panggil versi 2 (int)
    printStatus(80, 24.5);   // Panggil versi 3 (int, double)
    return 0;
}
