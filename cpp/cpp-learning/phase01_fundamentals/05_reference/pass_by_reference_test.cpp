// ============================================================
// Program 05d: Pass by const Reference
// Deskripsi : Membuktikan bahwa reference dan variabel asli
//             memiliki alamat memori yang SAMA.
// Konsep    : - &name (di fungsi) == &robot (di main)
//             - Reference hanyalah alias/nama lain
//             - const reference: aman dan efisien untuk baca
// ============================================================

#include <iostream>
#include <string>

// const reference: alamat sama, tapi tidak bisa ubah nilai
void printName(const std::string &name)
{
    std::cout << "Alamat di fungsi : "
              << &name << '\n';

    std::cout << "Robot : "
              << name << '\n';
}

int main()
{
    std::string robot = "NUIN-AMR-01";

    std::cout << "Alamat di main   : "
              << &robot << '\n';

    // Alamat yang dicetak di main dan di fungsi akan SAMA
    printName(robot);

    return 0;
}
