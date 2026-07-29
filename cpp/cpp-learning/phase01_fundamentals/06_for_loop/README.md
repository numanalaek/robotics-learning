# 06 — For Loop

Penggunaan `for` loop untuk membaca dan memproses array data sensor.

## Empat Hal Penting tentang For Loop

| # | Konsep | Contoh |
|---|--------|--------|
| 1 | `for` mengulang kode dengan **counter** | `for (int i = 0; i < N; ++i)` |
| 2 | Array menyimpan banyak data dengan **indeks 0..n-1** | `sensors[i]` |
| 3 | Akumulasi nilai dengan `sum += sensors[i]` | `sum += sensors[i];` |
| 4 | Cari min/max dengan **perbandingan** tiap iterasi | `if (sensors[i] < min) min = sensors[i];` |

## Kode — `for_loop.cpp`

```cpp
#include <iostream>

int main()
{
    constexpr int SENSOR_COUNT = 8;
    int sensors[SENSOR_COUNT] =
        {120, 45, 80, 30, 65, 90, 20, 55};

    int sensor_sum = 0;
    int min = sensors[0];
    int max = sensors[0];
    int warning_count = 0;

    for (int i = 0; i < SENSOR_COUNT; ++i)
    {
        std::cout << "Sensor " << i << " = " << sensors[i] << " cm";

        if (sensors[i] < 50)
        {
            std::cout << "  <-- WARNING";
            ++warning_count;
        }
        std::cout << '\n';

        sensor_sum += sensors[i];

        if (sensors[i] < min) min = sensors[i];
        if (sensors[i] > max) max = sensors[i];
    }

    int safe_count = SENSOR_COUNT - warning_count;
    double average = static_cast<double>(sensor_sum) / SENSOR_COUNT;

    std::cout << "\n--- Statistics ---\n";
    std::cout << "Minimum : " << min << " cm\n";
    std::cout << "Maximum : " << max << " cm\n";
    std::cout << "Average : " << average << " cm\n";

    std::cout << "\nWarning : " << warning_count << "\n";
    std::cout << "Safe    : " << safe_count << "\n";

    std::cout << "\nRobot Status : ";
    if (warning_count == 0)
        std::cout << "SAFE\n";
    else if (warning_count <= 2)
        std::cout << "CAUTION\n";
    else
        std::cout << "EMERGENCY\n";

    return 0;
}
```

## Output

```
Sensor 0 = 120 cm
Sensor 1 = 45 cm  <-- WARNING
Sensor 2 = 80 cm
Sensor 3 = 30 cm  <-- WARNING
Sensor 4 = 65 cm
Sensor 5 = 90 cm
Sensor 6 = 20 cm  <-- WARNING
Sensor 7 = 55 cm

--- Statistics ---
Minimum : 20 cm
Maximum : 120 cm
Average : 63.125 cm

Warning : 3
Safe    : 5

Robot Status : EMERGENCY
```

## Alur Eksekusi For Loop

```
for (int i = 0;    i < SENSOR_COUNT;    ++i)
      ①              ②                   ④
      ③
```

| Langkah | Kode | Penjelasan |
|---------|------|------------|
| ① | `int i = 0` | Inisialisasi (sekali di awal) |
| ② | `i < 8` | Cek kondisi — jika true, masuk loop |
| ③ | `sensors[i]` | Eksekusi body loop |
| ④ | `++i` | Increment, lalu kembali ke ② |

## Command Line

```bash
g++ for_loop.cpp -o for_loop && ./for_loop
g++ for_loop_test1.cpp -o for_loop_test1 && ./for_loop_test1
g++ robot_monitor.cpp -o robot_monitor && ./robot_monitor
```

## Analogi

For loop seperti **robot inspection line** — robot berjalan menyusuri 8 sensor, satu per satu.

| Bagian Loop | Analogi |
|-------------|---------|
| `int i = 0` | Mulai dari sensor pertama |
| `i < 8` | Cek apakah masih ada sensor |
| `sensors[i]` | Baca nilai sensor ke-i |
| `++i` | Geser ke sensor berikutnya |

## Latihan

1. Ubah `SENSOR_COUNT` jadi 16 — apa yang perlu diubah di array?
2. Ganti threshold warning dari 50 jadi 70 — bagaimana hasilnya?
3. Tambah logika: jika `warning_count >= 4`, cetak "EMERGENCY STOP!".
4. Gunakan `for (int i = 7; i >= 0; --i)` — apa yang terjadi pada urutan output?
