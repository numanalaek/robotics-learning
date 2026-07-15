// ============================================================
// Program 06a: For Loop - Analisis Sensor Robot
// Deskripsi : Membaca 8 sensor jarak, menghitung statistik
//             (min, max, rata-rata), dan menentukan status robot.
// Konsep    : - for loop: iterasi dengan counter i dari 0 ke n-1
//             - Array: menyimpan banyak data dengan tipe sama
//             - Mencari nilai minimum dan maksimum
//             - Menghitung rata-rata
//             - Logika kondisi untuk status robot
// ============================================================

#include <iostream>

int main()
{
    constexpr int SENSOR_COUNT = 8;   // Jumlah sensor

    // Array data sensor jarak (dalam cm)
    int sensors[SENSOR_COUNT] =
        {
            120, 45, 80, 30,
            65, 90, 20, 55};

    int sensor_sum = 0;       // total semua nilai sensor
    int min = sensors[0];     // inisialisasi min dengan data pertama
    int max = sensors[0];     // inisialisasi max dengan data pertama
    int warning_count = 0;    // jumlah sensor yang mendeteksi bahaya

    // 1. For loop: mulai dari i=0 selama i < SENSOR_COUNT
    //    Setiap iterasi i bertambah 1 (++i)
    for (int i = 0; i < SENSOR_COUNT; ++i)
    {
        std::cout << "Sensor " << i << " = " << sensors[i] << " cm";

        // Jika jarak < 50 cm, anggap berbahaya
        if (sensors[i] < 50)
        {
            std::cout << "  <-- WARNING";
            ++warning_count;
        }

        std::cout << '\n';

        sensor_sum += sensors[i];  // Akumulasi total

        // Update minimum
        if (sensors[i] < min)
            min = sensors[i];

        // Update maksimum
        if (sensors[i] > max)
            max = sensors[i];
    }

    // 2. Hitung statistik
    int safe_count = SENSOR_COUNT - warning_count;
    double average = static_cast<double>(sensor_sum) / SENSOR_COUNT;

    // 3. Tampilkan hasil
    std::cout << "\n--- Statistics ---\n";
    std::cout << "Minimum : " << min << " cm\n";
    std::cout << "Maximum : " << max << " cm\n";
    std::cout << "Average : " << average << " cm\n";

    std::cout << "\nWarning : " << warning_count << "\n";
    std::cout << "Safe    : " << safe_count << "\n";

    // 4. Tentukan status robot berdasarkan jumlah warning
    std::cout << "\nRobot Status : ";
    if (warning_count == 0)
        std::cout << "SAFE\n";
    else if (warning_count <= 2)
        std::cout << "CAUTION\n";
    else
        std::cout << "EMERGENCY\n";

    return 0;
}
