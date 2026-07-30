// ============================================================
// Program 10c: Block Scope
// Description: Shows that variables declared inside
//             { } (block scope) cannot be accessed
//             from outside the block.
// Concepts  : - battery = 100 (local to main, accessible from
//               both inside and outside the block)
//             - voltage = 24 (block scope, only inside { })
//             - Try uncommenting the std::cout << voltage line
//               outside the block to see a compilation error
// ============================================================

#include <iostream>

int main()
{
    int battery = 100;

    std::cout << "Outside block: "
              << battery
              << '\n';

    {
        int voltage = 24;

        std::cout << "Inside block:\n";
        std::cout << "Battery : " << battery << '\n';
        std::cout << "Voltage : " << voltage << '\n';
    }

    std::cout << "Outside block again:\n";
    std::cout << "Battery : " << battery << '\n';

    // std::cout << voltage << '\n'; // ERROR

    return 0;
}
