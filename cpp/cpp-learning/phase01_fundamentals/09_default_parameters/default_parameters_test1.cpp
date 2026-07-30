// ============================================================
// Program 09b: Simple Default Parameter
// Description: printStatus function with 1 default parameter.
// Concepts  : - printStatus()     -> battery=100 (default)
//             - printStatus(80)   -> battery=80
//             - Defaults make arguments optional
// ============================================================

#include <iostream>

// battery has a default value of 100
void printStatus(int battery = 100)
{
    std::cout << "Battery : " << battery << "%\n";
}

int main()
{
    printStatus();   // Use default: battery = 100
    printStatus(80); // Use argument: battery = 80

    return 0;
}
