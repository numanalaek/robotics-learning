// ============================================================
// Program 05a: Pass by Value
// Deskripsi : Mendemonstrasikan bahwa pass by value membuat
//             SALINAN (copy) dari data, sehingga fungsi tidak
//             bisa mengubah variabel asli di main().
// Konsep    : - Parameter tanpa & = pass by value
//             - Fungsi menerima COPY, alamat memori berbeda
//             - Perubahan di fungsi TIDAK mempengaruhi asli
// ============================================================

#include <iostream>
#include <string>

// name adalah salinan (copy) dari robot di main()
// Alamat name berbeda dari alamat robot
void printName(std::string name)
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

    printName(robot);  // robot di-copy ke parameter name

    // robot tetap "NUIN-AMR-01", tidak berubah menjadi "MODIFIED"
    std::cout << "Isi di main setelah fungsi : " << robot << '\n';

    return 0;
}
