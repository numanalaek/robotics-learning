# 08 — Function Overloading

Mendefinisikan beberapa fungsi dengan **nama sama** tetapi **parameter berbeda**.

## Empat Hal Penting tentang Function Overloading

| # | Konsep | Contoh |
|---|--------|--------|
| 1 | Nama fungsi **sama**, parameter **berbeda** | `void printStatus();` vs `void printStatus(int);` |
| 2 | Compiler memilih fungsi **cocok** dengan argumen | `printStatus(80)` → panggil versi `int` |
| 3 | Bisa berbeda dalam **jumlah** atau **tipe** parameter | `(int)` vs `(int, double)` |
| 4 | Tidak bisa dibedakan hanya dari **return type** | `int foo();` dan `void foo();` ❌ error |

## Kode — `function_overloading.cpp`

```cpp
#include <iostream>

void printStatus()
{
    std::cout << "Robot READY\n";
}

void printStatus(int battery)
{
    std::cout << "Battery : " << battery << "%\n";
}

void printStatus(int battery, double voltage)
{
    std::cout << "Battery : " << battery << "%\n";
    std::cout << "Voltage : " << voltage << " V\n";
}

int main()
{
    printStatus();
    printStatus(80);
    printStatus(80, 24.5);
    return 0;
}
```

## Output

```
Robot READY
Battery : 80%
Battery : 80%
Voltage : 24.5 V
```

## Cara Kerja Overloading

```
printStatus()           → panggil void printStatus()
printStatus(80)         → panggil void printStatus(int)
printStatus(80, 24.5)   → panggil void printStatus(int, double)
```

Compiler mencocokkan **jumlah** dan **tipe** argumen dengan parameter yang tersedia.

## Program Lain

| File | Overloading |
|------|-------------|
| `function_overloading_test1.cpp` | `move()` dan `move(int step)` |
| `function_overloading_test2.cpp` | `setSpeed(int)` dan `setSpeed(double)` |

## Syarat Overloading

| Bisa | Tidak Bisa |
|------|------------|
| Beda jumlah parameter | Hanya beda return type |
| Beda tipe parameter | Parameter sama, nama berbeda |
| `(int)` vs `(double)` | `(int)` vs `(int)` — duplikat |

## Command Line

```bash
g++ function_overloading.cpp -o function_overloading && ./function_overloading
g++ function_overloading_test1.cpp -o function_overloading_test1 && ./function_overloading_test1
g++ function_overloading_test2.cpp -o function_overloading_test2 && ./function_overloading_test2
```

## Analogi

Overloading seperti **remote control universal** — tombol "ON" berbeda arti tergantung device yang dituju.

| Panggilan | Remote | Aksi |
|-----------|--------|------|
| `printStatus()` | Tekan "Status" tanpa device | "Robot READY" |
| `printStatus(80)` | Tekan "Status" → TV | "Battery: 80%" |
| `printStatus(80, 24.5)` | Tekan "Status" → AC | "Battery: 80%, Voltage: 24.5V" |

## Latihan

1. Tambah overload `printStatus(double voltage)` — hanya cetak tegangan. Apa yang terjadi?
2. Buat overload `printStatus(int battery, bool emergency)`.
3. Compile `printStatus(80, 24);` — overload mana yang dipanggil? Kenapa?
4. Bisakah `void printStatus(int a)` dan `void printStatus(int b)` di-overload? Mengapa?
