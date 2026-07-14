#include <iostream>

void printStatus()
{
    std::cout << "Robot READY\n";
}

void printStatus(int battery)
{
    std::cout << "Battery : "
              << battery
              << "%\n";
}

void printStatus(int battery, double voltage)
{
    std::cout << "Battery : "
              << battery
              << "%\n";

    std::cout << "Voltage : "
              << voltage
              << " V\n";
}

int main()
{
    printStatus();
    printStatus(80);
    printStatus(80, 24.5);
    return 0;
}
