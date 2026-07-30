// ============================================================
// Program 03a: Memory and Addresses
// Description: Displays variable values along with the memory
//             addresses where the variables are stored.
// Concepts  : - Every variable has a unique address in memory
//             - The & operator gets the variable's address
//             - static_cast<void*> is needed for char because
//               cout would interpret char* as a string
//             - Memory addresses are displayed in hexadecimal format
// ============================================================

#include <iostream>

int main()
{
    // Declare variables with different types
    int battery = 100;     // int: 4 bytes
    double voltage = 24.6; // double: 8 bytes
    char command = 'W';    // char: 1 byte

    // Print the VALUE of each variable
    std::cout << "battery : " << battery << '\n';
    std::cout << "voltage : " << voltage << '\n';
    std::cout << "command : " << command << '\n';

    // Print the MEMORY ADDRESS of each variable
    // The & operator returns the address where the variable is stored
    std::cout << "\nAddress\n";

    std::cout << "battery : " << &battery << '\n';
    std::cout << "voltage : " << &voltage << '\n';
    // static_cast<void*> is needed so char* is not interpreted as a string
    std::cout << "command : " << static_cast<void *>(&command) << '\n';

    return 0;
}
