// ============================================================
// Program 07e: Range-based For dengan Reference
// Deskripsi : Menggunakan "int &sensor" (reference) agar
//             bisa mengubah array asli dari dalam loop.
// Konsep    : - int &sensor : sensors => sensor adalah reference
//             - Mengubah sensor JUGA mengubah array asli
//             - Gunakan reference jika perlu memodifikasi data
// ============================================================

#include <iostream>

int main()
{
    int sensors[] = {120, 45, 80, 30, 65, 90, 20, 55};

    std::cout << "Before:\n";
    for (int sensor : sensors)
    {
        std::cout << sensor << ' ';
    }
    std::cout << '\n';

    // &sensor adalah reference, bukan copy -> array asli BERUBAH
    for (int &sensor : sensors)
    {
        sensor = 0;
    }

    std::cout << "After:\n";
    for (int sensor : sensors)
    {
        std::cout << sensor << ' ';
    }
    std::cout << '\n';

    std::cout << "Array berubah karena sensor adalah reference.\n";

    return 0;
}
