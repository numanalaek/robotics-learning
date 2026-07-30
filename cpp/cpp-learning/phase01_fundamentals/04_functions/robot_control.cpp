// ============================================================
// Program 04: Functions and Robot Control (Simulation)
// Description: Simple robot control simulation with functions.
//             Robot can move forward, backward, turn left/right.
// Concepts  : - Functions: break program into small parts
//             - Pass by reference (&): function can modify
//               original variables (x, y, dir, battery)
//             - Pass by value (without &): function only receives a copy
//             - switch-case to handle commands
//             - while loop for interactive program
// ============================================================

#include <iostream>

// Print program header
void printHeader()
{
    std::cout << "==============================\n";
    std::cout << "    ROBOT CONTROL PROGRAM     \n";
    std::cout << "==============================\n";
}

// Display robot position, direction, and battery
void printStatus(int x, int y, int dir, int battery)
{
    const char *arah[] = {"North", "East", "South", "West"};
    std::cout << "Position : (" << x << ", " << y << ")\n";
    std::cout << "Direction: " << arah[dir] << "\n";
    std::cout << "Battery  : " << battery << "%\n";
    std::cout << "------------------------------\n";
}

// Reduce battery by 1% (pass by reference so original value changes)
void consumeBattery(int &battery)
{
    if (battery > 0)
    {
        battery -= 1;
        if (battery < 0)
            battery = 0;
    }
}

// Move forward according to direction
void moveForward(int &x, int &y, int dir, int &battery)
{
    if (battery <= 0)
    {
        std::cout << "[FAIL] Battery empty!\n";
        return;
    }
    switch (dir)
    {
    case 0: y++; break; // North: Y + 1
    case 1: x++; break; // East: X + 1
    case 2: y--; break; // South: Y - 1
    case 3: x--; break; // West: X - 1
    }
    consumeBattery(battery);
    const char *arah[] = {"North", "East", "South", "West"};
    std::cout << "[OK] Move to " << arah[dir] << " | Battery: " << battery << "%\n";
}

// Turn left (rotate 90 degrees)
void turnLeft(int &dir, int &battery)
{
    if (battery <= 0)
    {
        std::cout << "[FAIL] Battery empty!\n";
        return;
    }
    dir = (dir + 3) % 4; // Shift direction left
    consumeBattery(battery);
    std::cout << "[OK] Turn left | Battery: " << battery << "%\n";
}

// Turn right (rotate -90 degrees)
void turnRight(int &dir, int &battery)
{
    if (battery <= 0)
    {
        std::cout << "[FAIL] Battery empty!\n";
        return;
    }
    dir = (dir + 1) % 4; // Shift direction right
    consumeBattery(battery);
    std::cout << "[OK] Turn right | Battery: " << battery << "%\n";
}

// Move backward (opposite of forward)
void moveBackward(int &x, int &y, int dir, int &battery)
{
    if (battery <= 0)
    {
        std::cout << "[FAIL] Battery empty!\n";
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
    std::cout << "[OK] Move backward | Battery: " << battery << "%\n";
}

int main()
{
    int x = 0, y = 0;  // Robot position
    int dir = 0;        // Direction: 0=North, 1=East, 2=South, 3=West
    int battery = 100;  // Initial battery 100%

    printHeader();
    printStatus(x, y, dir, battery);

    char cmd;
    while (true)
    {
        std::cout << "\nEnter command (w: forward, s: backward, a: left, d: right, q: quit): ";
        std::cin >> cmd;

        switch (cmd)
        {
        case 'w': moveForward(x, y, dir, battery); break;
        case 's': moveBackward(x, y, dir, battery); break;
        case 'a': turnLeft(dir, battery); break;
        case 'd': turnRight(dir, battery); break;
        case 'q':
            std::cout << "Program finished.\n";
            return 0;
        default:
            std::cout << "[ERROR] Unknown command!\n";
            continue;
        }
        printStatus(x, y, dir, battery);
    }

    return 0;
}
