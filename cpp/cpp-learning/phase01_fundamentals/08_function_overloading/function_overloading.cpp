// ============================================================
// Program 08a: Function Overloading
// Description: Demonstrates function overloading - multiple
//             functions with the SAME NAME but DIFFERENT parameters.
// Concepts  : - C++ distinguishes functions by number/type
//               of parameters (not name)
//             - printStatus() without parameters
//             - printStatus(int) with 1 parameter
//             - printStatus(int, double) with 2 parameters
//             - Compiler automatically selects the matching function
// ============================================================

#include <iostream>

// Version 1: without parameters
void printStatus()
{
    std::cout << "Robot READY\n";
}

// Version 2: one int parameter (battery)
void printStatus(int battery)
{
    std::cout << "Battery : " << battery << "%\n";
}

// Version 3: two parameters int and double (battery, voltage)
void printStatus(int battery, double voltage)
{
    std::cout << "Battery : " << battery << "%\n";
    std::cout << "Voltage : " << voltage << " V\n";
}

int main()
{
    // Compiler selects the function matching the arguments
    printStatus();           // Call version 1 (no parameters)
    printStatus(80);         // Call version 2 (int)
    printStatus(80, 24.5);   // Call version 3 (int, double)
    return 0;
}
