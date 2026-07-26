// ============================================================
// Program 10e: Lifetime Sederhana — Block
// Deskripsi : Menunjukkan masa hidup variabel dalam block.
//             sensor_distance dibuat di dalam { } dan otomatis
//             dihancurkan saat block selesai ( } ).
// Konsep    : - Objek lokal di block hanya hidup selama
//               eksekusi di dalam block tersebut
//             - Setelah } , objek tidak lagi ada di memori
// ============================================================

#include <iostream>

int main()
{
    std::cout << "Program started\n";

    {
        int sensor_distance = 45;

        std::cout << "Sensor active\n";
    }

    std::cout << "Sensor block finished\n";

    return 0;
}
