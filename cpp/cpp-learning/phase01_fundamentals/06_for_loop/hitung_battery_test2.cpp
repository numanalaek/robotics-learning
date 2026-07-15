// ============================================================
// Program 06c: For Loop - Simulasi Baterai
// Deskripsi : Mensimulasikan baterai robot yang berkurang
//             setiap langkah dengan jeda 1 detik.
// Konsep    : - for loop dari 0 sampai 99 (100 iterasi)
//             - Dekrementasi battery setiap langkah
//             - std::this_thread::sleep_for untuk jeda waktu
//             - #include <thread> dan <chrono> untuk waktu
// ============================================================

#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    int battery = 100;

    // Loop 100 kali (i = 0..99), setiap langkah baterai berkurang 1
    for (int i = 0; i < 100; i++)
    {
        battery--;
        std::cout << "Move " << i + 1
                  << " Battery = "
                  << battery << "%\n";
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Jeda 1 detik
    }

    return 0;
}
