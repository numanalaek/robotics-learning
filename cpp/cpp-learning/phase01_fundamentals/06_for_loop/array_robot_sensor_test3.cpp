// ============================================================
// Program 06d: For Loop dengan Array
// Deskripsi : Menggunakan for loop untuk membaca 5 sensor
//             ultrasonik dan menampilkan nilainya.
// Konsep    : - Array: kumpulan data dengan indeks 0..n-1
//             - Akses array dengan sensors[i]
//             - i adalah indeks, sensors[i] adalah nilai
// ============================================================

#include <iostream>

int main()
{
    // Array dengan 5 elemen sensor jarak (cm)
    int ultrasonic[5] = {120, 98, 150, 110, 95};

    // Loop untuk membaca semua sensor
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Sensor "
                  << i
                  << " = "
                  << ultrasonic[i]
                  << " cm\n";
    }

    return 0;
}
