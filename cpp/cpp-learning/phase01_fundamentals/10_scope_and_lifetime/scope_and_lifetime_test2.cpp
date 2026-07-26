// ============================================================
// Program 10c: Block Scope
// Deskripsi : Menunjukkan bahwa variabel yang dideklarasikan
//             di dalam { } (block scope) tidak bisa diakses
//             dari luar block tersebut.
// Konsep    : - battery = 100 (local main, bisa diakses dari
//               dalam block maupun luar block)
//             - voltage = 24 (block scope, hanya di dalam { })
//             - Coba uncomment baris std::cout << voltage
//               di luar block untuk melihat error kompilasi
// ============================================================

#include <iostream>

int main()
{
    int battery = 100;

    std::cout << "Outside block: "
              << battery
              << '\n';

    {
        int voltage = 24;

        std::cout << "Inside block:\n";
        std::cout << "Battery : " << battery << '\n';
        std::cout << "Voltage : " << voltage << '\n';
    }

    std::cout << "Outside block again:\n";
    std::cout << "Battery : " << battery << '\n';

    // std::cout << voltage << '\n'; // ERROR

    return 0;
}
