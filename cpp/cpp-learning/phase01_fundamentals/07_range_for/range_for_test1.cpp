// ============================================================
// Program 07b: Basic Range-based For Loop
// Description: Reads 8 distance sensors using a range-based
//             for loop and displays their values.
// Concepts  : - for (int sensor : sensors)
//             - No need for index i, directly get the value
//             - sensor is a COPY of each array element
// ============================================================

#include <iostream>

int main()
{
    constexpr int SENSOR_COUNT = 8;

    int sensors[SENSOR_COUNT] =
        {
            120, 45, 80, 30,
            65, 90, 20, 55};

    // Range-based for: sensor will contain the value of each element
    for (int sensor : sensors)
    {
        std::cout << sensor << " cm\n";
    }

    return 0;
}
