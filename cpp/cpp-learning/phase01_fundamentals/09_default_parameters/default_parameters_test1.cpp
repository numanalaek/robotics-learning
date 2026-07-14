#include <iostream>

void printStatus(int battery = 100)
{
    std::cout << "Battery : "
              << battery
              << "%\n";
}

int main()
{
    printStatus();

    printStatus(80);

    return 0;
}
