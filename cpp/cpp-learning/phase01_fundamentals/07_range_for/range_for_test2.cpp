// ============================================================
// Program 07c: Range-based For - Sensor Average
// Description: Calculates the average of 8 sensors using
//             a range-based for loop.
// Concepts  : - Accumulate values with sum += sensor
//             - Calculate average after loop
//             - static_cast<double> for type conversion
// ============================================================

#include <iostream>

int main()
{
    int sensors[] = {120, 45, 80, 30, 65, 90, 20, 55};

    int sum = 0;

    // Sum all sensor values
    for (int sensor : sensors)
    {
        sum += sensor;
    }

    // Calculate average (convert to double for precision)
    double average = static_cast<double>(sum) / 8;

    std::cout << "Average = " << average << '\n';
}
