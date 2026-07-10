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
    if (battery > 0)
    {
        battery -= 1;
        if (battery < 0)
            battery = 0;
    }
}

void moveForward(int &x, int &y, int dir, int &battery)
{
    if (battery <= 0)
    {
        std::cout << "[GAGAL] Baterai habis!\n";
        return;
    }
    switch (dir)
    {
    case 0:
        y++;
        break;
    case 1:
        x++;
        break;
    case 2:
        y--;
        break;
    case 3:
        x--;
        break;
    }
    consumeBattery(battery);
    std::cout << "[OK] Maju ke ";
    const char *arah[] = {"Utara", "Timur", "Selatan", "Barat"};
    std::cout << arah[dir] << " | Baterai: " << battery << "%\n";
}

void turnLeft(int &dir, int &battery)
{
    if (battery <= 0)
    {
        std::cout << "[GAGAL] Baterai habis!\n";
        return;
    }
    dir = (dir + 3) % 4;
    consumeBattery(battery);
    std::cout << "[OK] Belok kiri | Baterai: " << battery << "%\n";
}

void turnRight(int &dir, int &battery)
{
    if (battery <= 0)
    {
        std::cout << "[GAGAL] Baterai habis!\n";
        return;
    }
    dir = (dir + 1) % 4;
    consumeBattery(battery);
    std::cout << "[OK] Belok kanan | Baterai: " << battery << "%\n";
}

void moveBackward(int &x, int &y, int dir, int &battery)
{
    if (battery <= 0)
    {
        std::cout << "[GAGAL] Baterai habis!\n";
        return;
    }
    switch (dir)
    {
    case 0:
        y--;
        break;
    case 1:
        x--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x++;
        break;
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
    while (true)
    {
        std::cout << "\nMasukkan perintah (w: maju, s: mundur, a: kiri, d: kanan, q: keluar): ";
        std::cin >> cmd;

        switch (cmd)
        {
        case 'w':
            moveForward(x, y, dir, battery);
            break;
        case 's':
            moveBackward(x, y, dir, battery);
            break;
        case 'a':
            turnLeft(dir, battery);
            break;
        case 'd':
            turnRight(dir, battery);
            break;
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
