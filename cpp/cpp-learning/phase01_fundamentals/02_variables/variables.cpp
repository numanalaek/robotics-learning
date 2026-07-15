// ============================================================
// Program 02: Variabel dan Tipe Data
// Deskripsi : Mendeklarasikan dan menampilkan berbagai tipe data
//             yang umum digunakan dalam pemrograman robot.
// Konsep    : - Berbagai tipe data: int, double, float, bool,
//               char, std::string
//             - constexpr untuk konstanta waktu kompilasi
//             - auto untuk deduksi tipe otomatis
//             - std::setw untuk merapikan tampilan
//             - Ternary operator (?:) untuk kondisi sederhana
// ============================================================

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    // ----- DEKLARASI VARIABEL DENGAN BERBAGAI TIPE DATA -----
    std::string robot_name = "NUIN-AMR-01";  // string: teks
    int robot_id = 1;                         // int: bilangan bulat
    int battery = 100;                        // int: persentase baterai
    double voltage = 24.6;                    // double: desimal presisi ganda
    float speed = 1.25f;                      // float: desimal presisi tunggal
    bool obstacle = false;                    // bool: true/false
    char command = 'W';                       // char: satu karakter

    // constexpr: nilai tetap yang sudah diketahui saat kompilasi
    constexpr int wheel_count = 2;
    constexpr double MAX_PAYLOAD = 500.0;

    // auto: compiler menentukan tipe secara otomatis
    const auto software_version = std::string("v1.0.0");

    // Ternary operator: if singkat dalam satu baris
    auto obstacle_str = obstacle ? "Yes" : "No";

    // ----- CETAK INFORMASI ROBOT -----
    std::cout << "==============================" << '\n';
    std::cout << "NUIN Autonomous Mobile Robot" << '\n';
    std::cout << "==============================" << '\n';
    std::cout << '\n';

    // std::left: rata kiri, std::fixed: format desimal tetap
    // std::setw(18): atur lebar kolom 18 karakter
    std::cout << std::left;
    std::cout << std::fixed;
    std::cout << std::setw(18) << "Robot Name" << ": " << robot_name << '\n';
    std::cout << std::setw(18) << "Robot ID" << ": " << robot_id << '\n';
    std::cout << std::setw(18) << "Battery" << ": " << battery << " %" << '\n';
    std::cout << std::setw(18) << "Voltage" << ": " << std::setprecision(1) << voltage << " V" << '\n';
    std::cout << std::setw(18) << "Speed" << ": " << std::setprecision(2) << speed << " m/s" << '\n';
    std::cout << std::setw(18) << "Obstacle" << ": " << obstacle_str << '\n';
    std::cout << std::setw(18) << "Command" << ": " << command << '\n';
    std::cout << std::setw(18) << "Wheel Count" << ": " << wheel_count << '\n';
    std::cout << std::setw(18) << "Max Payload" << ": " << std::setprecision(1) << MAX_PAYLOAD << " kg" << '\n';
    std::cout << std::setw(18) << "Software Version" << ": " << software_version << std::endl;

    return 0;
}
