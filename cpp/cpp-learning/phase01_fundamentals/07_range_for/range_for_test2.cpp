// ============================================================
// Program 07c: Range-based For - Rata-rata Sensor
// Deskripsi : Menghitung rata-rata dari 8 sensor menggunakan
//             range-based for loop.
// Konsep    : - Akumulasi nilai dengan sum += sensor
//             - Hitung rata-rata setelah loop
//             - static_cast<double> untuk konversi tipe
// ============================================================

#include <iostream>

int main()
{
    int sensors[] = {120, 45, 80, 30, 65, 90, 20, 55};

    int sum = 0;

    // Jumlahkan semua nilai sensor
    for (int sensor : sensors)
    {
        sum += sensor;
    }

    // Hitung rata-rata (konversi ke double agar presisi)
    double average = static_cast<double>(sum) / 8;

    std::cout << "Average = " << average << '\n';
}
