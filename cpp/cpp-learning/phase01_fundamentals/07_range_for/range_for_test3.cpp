// ============================================================
// Program 07d: Range-based For - Copy vs Reference
// Description: Proves that range-based for with
//             "int sensor" creates a COPY, so the original array
//             does not change even when set to 0.
// Concepts  : - int sensor : sensors => sensor is a COPY
//             - Changing sensor does NOT affect the original array
//             - To modify the original, use int &sensor
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

    // sensor here is a COPY, so the original array does NOT change
    for (int sensor : sensors)
    {
        sensor = 0;
    }

    std::cout << "After:\n";
    for (int sensor : sensors)
    {
        std::cout << sensor << ' ';
    }
    std::cout << '\n';

    std::cout << "Array did not change because sensor is a copy.\n";

    return 0;
}
