// ============================================================
// Program 05f: Reference is NOT a Pointer
// Description: Proves that a reference is an ALIAS (another
//             name), not a pointer. References do not have
//             their own memory address.
// Concepts  : - &ref == &battery (same address)
//             - ref is another name for battery
//             - Unlike a pointer which has its own address
//             - Changing ref = changing battery (and vice versa)
// ============================================================

#include <iostream>

int main()
{
    std::cout << "=== Proving that Reference is NOT a Pointer ===\n\n";

    int battery = 100;
    int &ref = battery;     // ref is an alias/another name for battery

    // battery and ref values are always the same
    std::cout << "Print values:\n";
    std::cout << "  battery = " << battery << "\n";
    std::cout << "  ref     = " << ref << "\n\n";

    // battery and ref addresses are also the SAME
    std::cout << "Print addresses:\n";
    std::cout << "  &battery = " << &battery << "\n";
    std::cout << "  &ref     = " << &ref << "\n\n";

    std::cout << "Is &battery == &ref ? "
              << (&battery == &ref ? "YES, addresses are the SAME" : "NOT SAME") << "\n\n";

    // Change through ref -> battery also changes
    std::cout << "Change value through ref:\n";
    ref = 75;
    std::cout << "  ref = 75;\n";
    std::cout << "  battery = " << battery << "\n";
    std::cout << "  ref     = " << ref << "\n\n";

    // Change through battery -> ref also changes
    std::cout << "Change value through battery:\n";
    battery = 50;
    std::cout << "  battery = 50;\n";
    std::cout << "  battery = " << battery << "\n";
    std::cout << "  ref     = " << ref << "\n\n";

    std::cout << "Conclusion:\n";
    std::cout << "- ref and battery are TWO NAMES for the SAME variable.\n";
    std::cout << "- ref does NOT have its own address (&ref == &battery).\n";
    std::cout << "- Pointers have their own address (&ptr != &battery).\n";
    std::cout << "- Reference is just an alias (another name), not a separate object.\n";

    return 0;
}
