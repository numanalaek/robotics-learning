# 04 — Functions

Function implementation to control a robot moving on a 2D plane.

## Four Important Things about Functions

| # | Concept | Example |
|---|--------|--------|
| 1 | Functions break a program into small **sub-programs** | `void moveForward(int &x, int &y);` |
| 2 | **Pass by reference** (`&`) modifies the original variable | `int &battery` — battery in main changes |
| 3 | **Pass by value** (without `&`) only receives a copy | `int battery` — copy, original unchanged |
| 4 | Functions can have **parameters** and **return values** | `int add(int a, int b) { return a + b; }` |

## Code — `robot_control.cpp`

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

## Analogy

Functions are like **subroutines in robot control**.

| Function | Analogy |
|--------|---------|
| `printHeader()` | Display logo at startup |
| `moveForward()` | Execute "move forward" command |
| `consumeBattery()` | Reduce power with each movement |
| `printStatus()` | Update HMI dashboard |

## Exercises

1. Add a `stop()` function — set speed to 0.
2. Change `consumeBattery` to reduce 2% per step (instead of 1%).
3. Add parameter `int speed` to `moveForward` — faster speed drains more battery.
4. Create a `turnAround()` function — turn 180 degrees (call `turnLeft` twice).
