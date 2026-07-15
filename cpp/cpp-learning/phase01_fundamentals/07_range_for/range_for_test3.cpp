// ============================================================
// Program 07d: Range-based For - Copy vs Reference
// Deskripsi : Membuktikan bahwa range-based for dengan
//             "int sensor" membuat COPY, sehingga array asli
//             tidak berubah meskipun di-set ke 0.
// Konsep    : - int sensor : sensors => sensor adalah COPY
//             - Mengubah sensor TIDAK mempengaruhi array asli
//             - Untuk mengubah asli, pakai int &sensor
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

    // sensor di sini adalah COPY, jadi array asli TIDAK berubah
    for (int sensor : sensors)
    {
        sensor = 0;
    }

    std::cout << "After:\n";
    for (int sensor : sensors)
    {
        std::cout << sensor << ' ';
    }
    std::cout << '\n';

    std::cout << "Array tidak berubah karena sensor adalah copy.\n";

    return 0;
}
