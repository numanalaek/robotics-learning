// ============================================================
// Program 05g: Const Reference
// Description: Using const reference for parameters that
//             only need to be read (read-only), not modified.
// Concepts  : - const reference: cannot modify the original data
//             - Safer because it prevents accidental modification
//             - Still efficient because no copying occurs
//             - Best practice: use const reference for
//               large object parameters that only need reading
// ============================================================

#include <iostream>
#include <string>

// const reference: read only, cannot be modified
void printName(const std::string &name)
{
    std::cout << "Address in function : " << &name << '\n';
    std::cout << "Content in function : " << name << '\n';

    // name = "MODIFIED";  // ERROR: const reference cannot be modified
}

int main()
{
    std::string robot = "NUIN-AMR-01";

    std::cout << "Address in main    : " << &robot << '\n';
    std::cout << "Content in main    : " << robot << '\n';

    printName(robot);

    // robot stays "NUIN-AMR-01" because const reference cannot be changed
    std::cout << "Content in main after function : " << robot << '\n';

    return 0;
}
