// ============================================================
// Program 06a: For Loop - Robot Sensor Analysis
// Description: Reads 8 distance sensors, calculates statistics
//             (min, max, average), and determines robot status.
// Concepts  : - for loop: iteration with counter i from 0 to n-1
//             - Array: stores multiple data of the same type
//             - Finding minimum and maximum values
//             - Calculating average
//             - Conditional logic for robot status
// ============================================================

#include <iostream>

int main()
{
    constexpr int SENSOR_COUNT = 8;   // Number of sensors

    // Array of distance sensor data (in cm)
    int sensors[SENSOR_COUNT] =
        {
            120, 45, 80, 30,
            65, 90, 20, 55};

    int sensor_sum = 0;       // total of all sensor values
    int min = sensors[0];     // initialize min with first data
    int max = sensors[0];     // initialize max with first data
    int warning_count = 0;    // number of sensors detecting danger

    // 1. For loop: start from i=0 while i < SENSOR_COUNT
    //    Each iteration i increments by 1 (++i)
    for (int i = 0; i < SENSOR_COUNT; ++i)
    {
        std::cout << "Sensor " << i << " = " << sensors[i] << " cm";

        // If distance < 50 cm, consider dangerous
        if (sensors[i] < 50)
        {
            std::cout << "  <-- WARNING";
            ++warning_count;
        }

        std::cout << '\n';

        sensor_sum += sensors[i];  // Accumulate total

        // Update minimum
        if (sensors[i] < min)
            min = sensors[i];

        // Update maximum
        if (sensors[i] > max)
            max = sensors[i];
    }

    // 2. Calculate statistics
    int safe_count = SENSOR_COUNT - warning_count;
    double average = static_cast<double>(sensor_sum) / SENSOR_COUNT;

    // 3. Display results
    std::cout << "\n--- Statistics ---\n";
    std::cout << "Minimum : " << min << " cm\n";
    std::cout << "Maximum : " << max << " cm\n";
    std::cout << "Average : " << average << " cm\n";

    std::cout << "\nWarning : " << warning_count << "\n";
    std::cout << "Safe    : " << safe_count << "\n";

    // 4. Determine robot status based on warning count
    std::cout << "\nRobot Status : ";
    if (warning_count == 0)
        std::cout << "SAFE\n";
    else if (warning_count <= 2)
        std::cout << "CAUTION\n";
    else
        std::cout << "EMERGENCY\n";

    return 0;
}
