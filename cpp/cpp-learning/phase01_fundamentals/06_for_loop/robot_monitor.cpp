// ============================================================
// Program 06f: For Loop - Robot Monitor
// Description: Monitors 8 sensors, gives a warning if
//             any sensor detects a distance < 50 cm.
// Concepts  : - For loop with counter
//             - Accumulate total warning with ++
//             - Display summary after loop
// ============================================================

#include <iostream>

int main()
{
    constexpr int SENSOR_COUNT = 8;
    int sensors[SENSOR_COUNT] = {120, 45, 80, 30, 65, 90, 20, 55};
    int total_warning = 0;

    for (int i = 0; i < SENSOR_COUNT; i++)
    {
        std::cout << "Sensor " << i << " : "
                  << sensors[i] << " cm -> ";

        if (sensors[i] < 50)
        {
            std::cout << "WARNING\n";
            total_warning++;
        }
        else
        {
            std::cout << "SAFE\n";
        }
    }

    std::cout << "--------------------------------\n";
    std::cout << "Total Warning : " << total_warning << "\n";

    return 0;
}
