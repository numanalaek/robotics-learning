// ============================================================
// Program 05e: Comparison of Pass by Value vs Pass by Reference
// Description: Directly compares the differences between
//             pass by value and pass by reference.
// Concepts  : - Pass by value: copy, original value does NOT change
//             - Pass by reference: alias, original value CHANGES
//             - Different memory address (value) vs same (reference)
//             - With reference, the function modifies the original variable
// ============================================================

#include <iostream>

// Pass by value: battery is a COPY, different address
void decreaseByValue(int battery)
{
    std::cout << "  [decreaseByValue] &battery (in function) = " << &battery << "\n";
    battery -= 10;
    std::cout << "  [decreaseByValue] battery in function = " << battery << "\n";
}

// Pass by reference: battery is a REFERENCE, same address
void decreaseByReference(int &battery)
{
    std::cout << "  [decreaseByReference] &battery (in function) = " << &battery << "\n";
    battery -= 10;
    std::cout << "  [decreaseByReference] battery in function = " << battery << "\n";
}

int main()
{
    std::cout << "=== Difference between Pass by Value vs Pass by Reference ===\n\n";

    // ----- PASS BY VALUE -----
    int battery1 = 100;
    std::cout << "1) Pass by Value:\n";
    std::cout << "  &battery1 (in main) = " << &battery1 << "\n";
    std::cout << "  Before calling function: battery = " << battery1 << "\n";
    decreaseByValue(battery1);
    std::cout << "  After calling function: battery = " << battery1 << "\n";
    std::cout << "  -> Value does NOT change (different address -> copy).\n\n";

    // ----- PASS BY REFERENCE -----
    int battery2 = 100;
    std::cout << "2) Pass by Reference:\n";
    std::cout << "  &battery2 (in main) = " << &battery2 << "\n";
    std::cout << "  Before calling function: battery = " << battery2 << "\n";
    decreaseByReference(battery2);
    std::cout << "  After calling function: battery = " << battery2 << "\n";
    std::cout << "  -> Value CHANGES (same address -> original variable).\n";

    return 0;
}
