// ============================================================
// Program 05c: Pass by Reference
// Deskripsi : Mendemonstrasikan bahwa pass by reference
//             memungkinkan fungsi mengubah variabel asli.
// Konsep    : - Parameter &name = reference (alias) ke robot
//             - Alamat name SAMA dengan alamat robot
//             - Perubahan di fungsi JUGA mengubah variabel asli
//             - Reference lebih efisien karena tidak ada copy
// ============================================================

#include <iostream>
#include <string>

// name adalah reference (alias) ke robot di main()
// Alamat name SAMA dengan alamat robot
void printName(std::string &name)
{
    std::cout << "Alamat di fungsi : " << &name << '\n';
    std::cout << "Isi di fungsi    : " << name << '\n';
    name = "MODIFIED";
    std::cout << "Setelah diubah   : " << name << '\n';
}

int main()
{
    std::string robot = "NUIN-AMR-01";

    std::cout << "Alamat di main   : " << &robot << '\n';
    std::cout << "Isi di main      : " << robot << '\n';

    printName(robot);  // robot di-reference, bukan di-copy

    // robot BERUBAH menjadi "MODIFIED" karena fungsi mengubah asli
    std::cout << "Isi di main setelah fungsi : " << robot << '\n';

    return 0;
}
