// ============================================================
// Program 10e: Simple Lifetime — Block
// Description: Shows variable lifetime inside a block.
//             sensor_distance is created inside { } and automatically
//             destroyed when the block ends ( } ).
// Concepts  : - Local objects in a block only live during
//               execution inside that block
//             - After } , the object no longer exists in memory
// ============================================================

#include <iostream>

int main()
{
    std::cout << "Program started\n";

    {
        int sensor_distance = 45;

        std::cout << "Sensor active\n";
    }

    std::cout << "Sensor block finished\n";

    return 0;
}
