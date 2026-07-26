// ============================================================
// Program 10a: Scope — Global, Local, dan Block
// Deskripsi : Menunjukkan tiga level scope variabel:
//             - global : robot_id (dapat diakses di mana saja)
//             - local  : battery (hanya di dalam main)
//             - block  : sensor_distance (hanya di dalam { })
// Konsep    : - Scope menentukan di mana variabel bisa diakses
//             - Block scope: variabel di dalam { } tidak bisa
//               diakses dari luar { }
//             - Coba uncomment baris sensor_distance di luar
//               block untuk melihat error kompilasi
// ============================================================

#include <iostream>

int robot_id = 1;

int main()
{
    int battery = 100;

    std::cout << "Robot ID : " << robot_id << '\n';
    std::cout << "Battery  : " << battery << '\n';

    {
        int sensor_distance = 45;

        std::cout << "Sensor   : "
                  << sensor_distance
                  << " cm\n";
    }

    // Coba uncomment baris berikut untuk melihat error:
    // std::cout << sensor_distance << '\n';

    return 0;
}
