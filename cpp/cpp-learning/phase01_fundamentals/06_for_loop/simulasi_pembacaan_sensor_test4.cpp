// ============================================================
// Program 06e: For Loop - Deteksi Halangan
// Deskripsi : Membaca 7 sensor dan menentukan apakah ada
//             halangan (obstacle) berdasarkan jarak < 100 cm.
// Konsep    : - if-else di dalam for loop
//             - Logika: jika sensor[i] < 100 maka OBSTACLE
//             - else maka CLEAR (aman)
// ============================================================

#include <iostream>

int main()
{
    // Array sensor jarak (cm)
    int ultrasonic[7] = {120, 98, 150, 110, 95, 70, 130};

    for (int i = 0; i < 7; i++)
    {
        // Jika jarak < 100 cm, ada halangan
        if (ultrasonic[i] < 100)
        {
            std::cout << "Sensor " << i << " : OBSTACLE\n";
        }
        else
        {
            std::cout << "Sensor " << i << " : CLEAR\n";
        }
    }

    return 0;
}
