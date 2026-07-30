// ============================================================
// Program 05c: Pass by Reference
// Description: Demonstrates that pass by reference
//             allows the function to modify the original variable.
// Concepts  : - Parameter &name = reference (alias) to robot
//             - name's address is the SAME as robot's address
//             - Changes in the function ALSO modify the original
//             - Reference is more efficient because no copy is made
// ============================================================

#include <iostream>
#include <string>

// name is a reference (alias) to robot in main()
// name's address is the SAME as robot's address
void printName(std::string &name)
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

    printName(robot);  // robot is referenced, not copied

    // robot CHANGES to "MODIFIED" because the function modifies the original
    std::cout << "Content in main after function : " << robot << '\n';

    return 0;
}
