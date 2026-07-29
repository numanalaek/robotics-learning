# 09 — Default Parameters

Memberikan nilai default pada parameter fungsi sehingga bisa dipanggil dengan jumlah argumen bervariasi.

## Empat Hal Penting tentang Default Parameters

| # | Konsep | Contoh |
|---|--------|--------|
| 1 | Parameter bisa punya **nilai default** | `void func(int x = 10);` |
| 2 | Argumen diisi dari **kiri ke kanan** | Tidak bisa skip `func(, 20)` ❌ |
| 3 | Default hanya di **parameter paling kanan** | `void func(int a, int b = 5);` ✅ |
| 4 | Mengurangi kebutuhan **overloading** | 1 fungsi dengan default = 4 cara panggil |

## Kode — `default_parameters.cpp`

```cpp
#include <iomanip>
#include <iostream>

void robotStatus(
    int battery = 100,
    double voltage = 24.0,
    bool obstacle = false)
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout
        << "Battery  : " << battery << "%\n"
        << "Voltage  : " << voltage << " V\n"
        << "Obstacle : " << (obstacle ? "YES" : "NO")
        << "\n\n";
}

int main()
{
    robotStatus();
    robotStatus(80);
    robotStatus(80, 23.5);
    robotStatus(80, 23.5, true);
    return 0;
}
```

## Output

```
Battery  : 100%
Voltage  : 24.0 V
Obstacle : NO

Battery  : 80%
Voltage  : 24.0 V
Obstacle : NO

Battery  : 80%
Voltage  : 23.5 V
Obstacle : NO

Battery  : 80%
Voltage  : 23.5 V
Obstacle : YES
```

## Cara Kerja

```
Panggilan                       battery    voltage    obstacle
─────────────────────────────────────────────────────────────
robotStatus()                      100       24.0       false
robotStatus(80)                     80       24.0       false
robotStatus(80, 23.5)               80       23.5       false
robotStatus(80, 23.5, true)         80       23.5       true
```

Parameter yang tidak diberi argumen akan menggunakan nilai default.

## Aturan Default Parameter

✅ **Boleh:**
```cpp
void func(int a, int b = 10);         // parameter kanan default
void func(int a = 1, int b = 2);      // semua default
void func(int a, int b = 5, int c = 0); // sebagian default
```

❌ **Tidak boleh:**
```cpp
void func(int a = 10, int b);         // kiri default, kanan tidak
void func(int a = 1, int b = 2, int c); // skip tengah
```

## Command Line

```bash
g++ default_parameters.cpp -o default_parameters && ./default_parameters
g++ default_parameters_test1.cpp -o default_parameters_test1 && ./default_parameters_test1
g++ default_parameters_test2.cpp -o default_parameters_test2 && ./default_parameters_test2
```

## Analogi

Default parameter seperti **preset mode pada robot**.

| Panggilan | Mode |
|-----------|------|
| `robotStatus()` | "Auto" — semua pakai default |
| `robotStatus(80)` | "Custom battery" — battery diatur, sisanya default |
| `robotStatus(80, 23.5)` | "Custom power" — battery & voltage diatur |
| `robotStatus(80, 23.5, true)` | "Manual" — semua diatur pengguna |

## Latihan

1. Ubah default `obstacle` jadi `true`. Panggil `robotStatus()` — apa outputnya?
2. Tambah parameter `int temperature = 25` di posisi paling kanan.
3. Panggil `robotStatus(80, true)` — apakah kompilasi error? Mengapa?
4. Buat fungsi `moveRobot(int steps = 1, double speed = 1.0)` — panggil dengan 3 cara berbeda.
