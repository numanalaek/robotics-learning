// ============================================================
// Program 05b: Pass by Value (Efficient with const Reference)
// Description: Using const reference so large data is not
//             copied, but also cannot be modified.
// Concepts  : - const std::string &name = read-only reference
//             - No data copying (faster)
//             - Original data is protected (const)
//             - This is the best approach for read-only parameters
// ============================================================

#include <iostream>
#include <string>

// const reference: read data without copy, without modifying original
void printName(const std::string &name)
{
    std::cout << "Robot : " << name << '\n';
    // name = "xxx"; // ERROR: const reference cannot be modified
}

int main()
{
    std::string robot = "NUIN-AMR-01";

    printName(robot);

    std::cout << "In main : " << robot << '\n';

    return 0;
}
