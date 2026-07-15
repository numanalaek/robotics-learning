// ============================================================
// Program 07b: Range-based For Loop Dasar
// Deskripsi : Membaca 8 sensor jarak menggunakan range-based
//             for loop dan menampilkan nilainya.
// Konsep    : - for (int sensor : sensors)
//             - Tidak perlu indeks i, langsung dapat nilai
//             - sensor adalah COPY dari setiap elemen array
// ============================================================

#include <iostream>

int main()
{
    constexpr int SENSOR_COUNT = 8;

    int sensors[SENSOR_COUNT] =
        {
            120, 45, 80, 30,
            65, 90, 20, 55};

    // Range-based for: sensor akan berisi nilai setiap elemen
    for (int sensor : sensors)
    {
        std::cout << sensor << " cm\n";
    }

    return 0;
}
