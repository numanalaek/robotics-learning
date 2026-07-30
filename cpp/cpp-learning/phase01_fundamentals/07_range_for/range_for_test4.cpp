// ============================================================
// Program 07e: Range-based For with Reference
// Description: Using "int &sensor" (reference) to
//             modify the original array from within the loop.
// Concepts  : - int &sensor : sensors => sensor is a reference
//             - Changing sensor ALSO changes the original array
//             - Use reference if you need to modify data
// ============================================================

#include <iostream>

int main()
{
    int sensors[] = {120, 45, 80, 30, 65, 90, 20, 55};

    std::cout << "Before:\n";
    for (int sensor : sensors)
    {
        std::cout << sensor << ' ';
    }
    std::cout << '\n';

    // &sensor is a reference, not a copy -> original array CHANGES
    for (int &sensor : sensors)
    {
        sensor = 0;
    }

    std::cout << "After:\n";
    for (int sensor : sensors)
    {
        std::cout << sensor << ' ';
    }
    std::cout << '\n';

    std::cout << "Array changed because sensor is a reference.\n";

    return 0;
}
