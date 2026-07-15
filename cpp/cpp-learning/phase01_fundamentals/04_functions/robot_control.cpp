// ============================================================
// Program 04: Fungsi dan Robot Control (Simulasi)
// Deskripsi : Simulasi kontrol robot sederhana dengan fungsi.
//             Robot bisa maju, mundur, belok kiri/kanan.
// Konsep    : - Fungsi: memecah program menjadi bagian kecil
//             - Pass by reference (&): fungsi bisa mengubah
//               variabel asli (x, y, dir, battery)
//             - Pass by value (tanpa &): fungsi hanya terima salinan
//             - switch-case untuk menangani perintah
//             - while loop untuk program interaktif
// ============================================================

#include <iostream>

// Cetak header program
void printHeader()
{
    std::cout << "==============================\n";
    std::cout << "    ROBOT CONTROL PROGRAM     \n";
    std::cout << "==============================\n";
}

// Tampilkan posisi, arah, dan baterai robot
void printStatus(int x, int y, int dir, int battery)
{
    const char *arah[] = {"Utara", "Timur", "Selatan", "Barat"};
    std::cout << "Posisi : (" << x << ", " << y << ")\n";
    std::cout << "Arah   : " << arah[dir] << "\n";
    std::cout << "Baterai: " << battery << "%\n";
    std::cout << "------------------------------\n";
}

// Kurangi baterai 1% (pass by reference agar nilai asli berubah)
void consumeBattery(int &battery)
{
    if (battery > 0)
    {
        battery -= 1;
        if (battery < 0)
            battery = 0;
    }
}

// Gerak maju sesuai arah
void moveForward(int &x, int &y, int dir, int &battery)
{
    if (battery <= 0)
    {
        std::cout << "[GAGAL] Baterai habis!\n";
        return;
    }
    switch (dir)
    {
    case 0: y++; break; // Utara: Y + 1
    case 1: x++; break; // Timur: X + 1
    case 2: y--; break; // Selatan: Y - 1
    case 3: x--; break; // Barat: X - 1
    }
    consumeBattery(battery);
    const char *arah[] = {"Utara", "Timur", "Selatan", "Barat"};
    std::cout << "[OK] Maju ke " << arah[dir] << " | Baterai: " << battery << "%\n";
}

// Belok kiri (berputar 90 derajat)
void turnLeft(int &dir, int &battery)
{
    if (battery <= 0)
    {
        std::cout << "[GAGAL] Baterai habis!\n";
        return;
    }
    dir = (dir + 3) % 4; // Geser arah ke kiri
    consumeBattery(battery);
    std::cout << "[OK] Belok kiri | Baterai: " << battery << "%\n";
}

// Belok kanan (berputar -90 derajat)
void turnRight(int &dir, int &battery)
{
    if (battery <= 0)
    {
        std::cout << "[GAGAL] Baterai habis!\n";
        return;
    }
    dir = (dir + 1) % 4; // Geser arah ke kanan
    consumeBattery(battery);
    std::cout << "[OK] Belok kanan | Baterai: " << battery << "%\n";
}

// Gerak mundur (kebalikan dari maju)
void moveBackward(int &x, int &y, int dir, int &battery)
{
    if (battery <= 0)
    {
        std::cout << "[GAGAL] Baterai habis!\n";
        return;
    }
    switch (dir)
    {
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
    int x = 0, y = 0;  // Posisi robot
    int dir = 0;        // Arah: 0=Utara, 1=Timur, 2=Selatan, 3=Barat
    int battery = 100;  // Baterai awal 100%

    printHeader();
    printStatus(x, y, dir, battery);

    char cmd;
    while (true)
    {
        std::cout << "\nMasukkan perintah (w: maju, s: mundur, a: kiri, d: kanan, q: keluar): ";
        std::cin >> cmd;

        switch (cmd)
        {
        case 'w': moveForward(x, y, dir, battery); break;
        case 's': moveBackward(x, y, dir, battery); break;
        case 'a': turnLeft(dir, battery); break;
        case 'd': turnRight(dir, battery); break;
        case 'q':
            std::cout << "Program selesai.\n";
            return 0;
        default:
            std::cout << "[ERROR] Perintah tidak dikenal!\n";
            continue;
        }
        printStatus(x, y, dir, battery);
    }

    return 0;
}
