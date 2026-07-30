// ============================================================
// Program 05d: Pass by const Reference
// Description: Proves that a reference and the original variable
//             have the SAME memory address.
// Concepts  : - &name (in function) == &robot (in main)
//             - Reference is just an alias/another name
//             - const reference: safe and efficient for reading
// ============================================================

#include <iostream>
#include <string>

// const reference: same address, but cannot change value
void printName(const std::string &name)
{
    std::cout << "Address in function : "
              << &name << '\n';

    std::cout << "Robot : "
              << name << '\n';
}

int main()
{
    std::string robot = "NUIN-AMR-01";

    std::cout << "Address in main    : "
              << &robot << '\n';

    // Addresses printed in main and in function will be the SAME
    printName(robot);

    return 0;
}
