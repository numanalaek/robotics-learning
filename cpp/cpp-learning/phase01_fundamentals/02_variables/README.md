# 02 — Variables

Mendeklarasikan dan menggunakan berbagai tipe data C++ dalam konteks robot.

## Empat Hal Penting tentang Variabel

| # | Konsep | Contoh |
|---|--------|--------|
| 1 | Setiap variabel punya **tipe data** | `int battery = 100;` |
| 2 | `std::string` untuk teks | `std::string name = "Robot";` |
| 3 | `constexpr` untuk konstanta waktu kompilasi | `constexpr int WHEELS = 2;` |
| 4 | `auto` mendeduksi tipe otomatis | `auto version = "v1.0";` |

## Kode — `variables.cpp`

```cpp
#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    std::string robot_name = "NUIN-AMR-01";
    int robot_id = 1;
    int battery = 100;
    double voltage = 24.6;
    float speed = 1.25f;
    bool obstacle = false;
    char command = 'W';

    constexpr int wheel_count = 2;
    constexpr double MAX_PAYLOAD = 500.0;

    const auto software_version = std::string("v1.0.0");
    auto obstacle_str = obstacle ? "Yes" : "No";

    std::cout << "==============================\n";
    std::cout << "NUIN Autonomous Mobile Robot\n";
    std::cout << "==============================\n\n";

    std::cout << std::left;
    std::cout << std::fixed;
    std::cout << std::setw(18) << "Robot Name" << ": " << robot_name << '\n';
    std::cout << std::setw(18) << "Robot ID" << ": " << robot_id << '\n';
    std::cout << std::setw(18) << "Battery" << ": " << battery << " %\n";
    std::cout << std::setw(18) << "Voltage" << ": "
              << std::setprecision(1) << voltage << " V\n";
    std::cout << std::setw(18) << "Speed" << ": "
              << std::setprecision(2) << speed << " m/s\n";
    std::cout << std::setw(18) << "Obstacle" << ": " << obstacle_str << '\n';
    std::cout << std::setw(18) << "Command" << ": " << command << '\n';
    std::cout << std::setw(18) << "Wheel Count" << ": " << wheel_count << '\n';
    std::cout << std::setw(18) << "Max Payload" << ": "
              << std::setprecision(1) << MAX_PAYLOAD << " kg\n";
    std::cout << std::setw(18) << "Software Version" << ": "
              << software_version << std::endl;

    return 0;
}
```

## Output

```
==============================
NUIN Autonomous Mobile Robot
==============================

Robot Name        : NUIN-AMR-01
Robot ID          : 1
Battery           : 100 %
Voltage           : 24.6 V
Speed             : 1.25 m/s
Obstacle          : No
Command           : W
Wheel Count       : 2
Max Payload       : 500.0 kg
Software Version  : v1.0.0
```

## Tipe Data

| Tipe | Ukuran | Contoh Robotik |
|------|--------|----------------|
| `int` | 4 byte | ID robot, jumlah roda, baterai |
| `double` | 8 byte | Tegangan, koordinat GPS |
| `float` | 4 byte | Kecepatan, suhu |
| `bool` | 1 byte | Deteksi obstacle, status darurat |
| `char` | 1 byte | Perintah gerak ('W', 'S', 'A', 'D') |
| `std::string` | dinamis | Nama robot, versi software |

## Command Line

```bash
g++ variables.cpp -o variables && ./variables
```

## Analogi

Variabel seperti **papan status di dashboard robot** — setiap papan menyimpan satu informasi dengan format tertentu.

| Papan Dashboard | Tipe | Isi |
|----------------|------|-----|
| Nama robot | `string` | "NUIN-AMR-01" |
| Baterai | `int` | 100 |
| Tegangan | `double` | 24.6 |
| Kecepatan | `float` | 1.25 |
| Halangan | `bool` | false |

## Latihan

1. Tambah variabel `int temperature = 45;` — cetak dengan `std::setw`.
2. Ubah nilai `obstacle` menjadi `true` — apa yang berubah pada output?
3. Ganti `constexpr` dengan `const` — apakah tetap jalan?
4. Gunakan `auto` untuk semua variabel — apakah tetap bisa dicetak?
