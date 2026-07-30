// ============================================================
// Program 07f: Range-based For - const Reference
// Description: Using const reference to read an array
//             without copying and without being able to modify the original data.
// Concepts  : - const int &sensor: read only, cannot modify
//             - Most efficient and safe for read iteration
//             - Three variants:
//               1. int sensor       -> copy (wasteful for large objects)
//               2. int &sensor      -> reference (can modify original)
//               3. const int &sensor -> const reference (read only)
// ============================================================

#include <iostream>

int main()
{
    int sensors[] = {120, 45, 80, 30, 65, 90, 20, 55};

    // const reference: efficient (no copy) and safe (cannot modify)
    for (const int &sensor : sensors)
    {
        std::cout << sensor << '\n';
    }

    return 0;
}

// 1. int sensor — copy, safe but wasteful for large objects
// 2. int &sensor — reference, can modify the original array
// 3. const int &sensor — const reference, read only without copy (most efficient & safe)
