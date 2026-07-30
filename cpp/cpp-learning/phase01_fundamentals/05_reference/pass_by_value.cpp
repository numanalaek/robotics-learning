// ============================================================
// Program 05a: Pass by Value
// Description: Demonstrates that pass by value creates a
//             COPY of the data, so the function cannot
//             change the original variable in main().
// Concepts  : - Parameter without & = pass by value
//             - Function receives a COPY, different memory address
//             - Changes in the function do NOT affect the original
// ============================================================

#include <iostream>
#include <string>

// name is a copy of robot in main()
// name's address is different from robot's address
void printName(std::string name)
{
    std::cout << "Address in function : " << &name << '\n';
    std::cout << "Content in function : " << name << '\n';
    name = "MODIFIED";
    std::cout << "After modification  : " << name << '\n';
}

int main()
{
    std::string robot = "NUIN-AMR-01";

    std::cout << "Address in main    : " << &robot << '\n';
    std::cout << "Content in main    : " << robot << '\n';

    printName(robot);  // robot is copied to parameter name

    // robot stays "NUIN-AMR-01", does not change to "MODIFIED"
    std::cout << "Content in main after function : " << robot << '\n';

    return 0;
}
