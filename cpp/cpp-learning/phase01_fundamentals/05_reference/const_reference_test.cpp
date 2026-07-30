// ============================================================
// Program 05h: Error Const Reference (Demo)
// Description: This program is intentionally made to ERROR to show
//             that a const reference CANNOT be modified.
// Concepts  : - const reference is read-only
//             - Trying to modify it will cause a compile error:
//               "assignment of read-only reference"
//             - This is a C++ safety feature
// ============================================================

#include <iostream>
#include <string>

void printName(const std::string &name)
{
    name = "TEST"; // ERROR: assignment of read-only reference 'name'
}

int main()
{
    std::string robot = "NUIN-AMR-01";
    printName(robot);
    return 0;
}
