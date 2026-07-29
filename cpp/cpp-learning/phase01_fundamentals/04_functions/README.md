# 04 — Functions

Implementasi fungsi untuk mengendalikan robot bergerak di bidang 2D.

## Empat Hal Penting tentang Fungsi

| # | Konsep | Contoh |
|---|--------|--------|
| 1 | Fungsi memecah program menjadi **sub-program** kecil | `void moveForward(int &x, int &y);` |
| 2 | **Pass by reference** (`&`) mengubah variabel asli | `int &battery` — battery di main berubah |
| 3 | **Pass by value** (tanpa `&`) hanya menerima salinan | `int battery` — copy, asli tidak berubah |
| 4 | Fungsi bisa punya **parameter** dan **return value** | `int add(int a, int b) { return a + b; }` |

## Kode — `robot_control.cpp`

```cpp
#include <iostream>

void printHeader()
{
    std::cout << "==============================\n";
    std::cout << "    ROBOT CONTROL PROGRAM     \n";
    std::cout << "==============================\n";
}

void printStatus(int x, int y, int dir, int battery)
{
    const char *arah[] = {"Utara", "Timur", "Selatan", "Barat"};
    std::cout << "Posisi : (" << x << ", " << y << ")\n";
    std::cout << "Arah   : " << arah[dir] << "\n";
    std::cout << "Baterai: " << battery << "%\n";
    std::cout << "------------------------------\n";
}

void consumeBattery(int &battery)
{
    if (battery > 0) {
        battery -= 1;
        if (battery < 0) battery = 0;
    }
}

void moveForward(int &x, int &y, int dir, int &battery)
{
    if (battery <= 0) { std::cout << "[GAGAL] Baterai habis!\n"; return; }
    switch (dir) {
    case 0: y++; break;
    case 1: x++; break;
    case 2: y--; break;
    case 3: x--; break;
    }
    consumeBattery(battery);
    const char *arah[] = {"Utara", "Timur", "Selatan", "Barat"};
    std::cout << "[OK] Maju ke " << arah[dir] << " | Baterai: " << battery << "%\n";
}

void turnLeft(int &dir, int &battery)
{
    if (battery <= 0) { std::cout << "[GAGAL] Baterai habis!\n"; return; }
    dir = (dir + 3) % 4;
    consumeBattery(battery);
    std::cout << "[OK] Belok kiri | Baterai: " << battery << "%\n";
}

void turnRight(int &dir, int &battery)
{
    if (battery <= 0) { std::cout << "[GAGAL] Baterai habis!\n"; return; }
    dir = (dir + 1) % 4;
    consumeBattery(battery);
    std::cout << "[OK] Belok kanan | Baterai: " << battery << "%\n";
}

void moveBackward(int &x, int &y, int dir, int &battery)
{
    if (battery <= 0) { std::cout << "[GAGAL] Baterai habis!\n"; return; }
    switch (dir) {
    case 0: y--; break;
    case 1: x--; break;
    case 2: y++; break;
    case 3: x++; break;
    }
    consumeBattery(battery);
    std::cout << "[OK] Mundur | Baterai: " << battery << "%\n";
}

int main()
{
    int x = 0, y = 0;
    int dir = 0;
    int battery = 100;

    printHeader();
    printStatus(x, y, dir, battery);

    char cmd;
    while (true) {
        std::cout << "\nMasukkan perintah (w: maju, s: mundur, a: kiri, d: kanan, q: keluar): ";
        std::cin >> cmd;
        switch (cmd) {
        case 'w': moveForward(x, y, dir, battery); break;
        case 's': moveBackward(x, y, dir, battery); break;
        case 'a': turnLeft(dir, battery); break;
        case 'd': turnRight(dir, battery); break;
        case 'q': std::cout << "Program selesai.\n"; return 0;
        default: std::cout << "[ERROR] Perintah tidak dikenal!\n"; continue;
        }
        printStatus(x, y, dir, battery);
    }
}
```

## Output (input `q`)

```
==============================
    ROBOT CONTROL PROGRAM     
==============================
Posisi : (0, 0)
Arah   : Utara
Baterai: 100%
------------------------------

Masukkan perintah (w: maju, s: mundur, a: kiri, d: kanan, q: keluar): Program selesai.
```

## Command Line

```bash
g++ robot_control.cpp -o robot_control && ./robot_control
```

## Analogi

Fungsi adalah seperti **sub-rutin dalam kontrol robot**.

| Fungsi | Analogi |
|--------|---------|
| `printHeader()` | Menampilkan logo di startup |
| `moveForward()` | Eksekusi perintah "maju" |
| `consumeBattery()` | Kurangi daya setiap gerakan |
| `printStatus()` | Update dashboard HMI |

## Latihan

1. Tambah fungsi `stop()` — set kecepatan jadi 0.
2. Ubah `consumeBattery` kurangi 2% per langkah (bukan 1%).
3. Tambah parameter `int speed` ke `moveForward` — makin cepat makin boros baterai.
4. Buat fungsi `turnAround()` — belok 180 derajat (panggil `turnLeft` 2 kali).
