// ============================================================
// Program 10a: Scope — Global, Local, and Block
// Description: Shows three levels of variable scope:
//             - global : robot_id (accessible anywhere)
//             - local  : battery (only inside main)
//             - block  : sensor_distance (only inside { })
// Concepts  : - Scope determines where a variable can be accessed
//             - Block scope: variables inside { } cannot
//               be accessed from outside { }
//             - Try uncommenting the sensor_distance line outside
//               the block to see a compilation error
// ============================================================

#include <iostream>

int robot_id = 1;

int main()
{
    int battery = 100;

    std::cout << "Robot ID : " << robot_id << '\n';
    std::cout << "Battery  : " << battery << '\n';

    {
        int sensor_distance = 45;

        std::cout << "Sensor   : "
                  << sensor_distance
                  << " cm\n";
    }

    // Try uncommenting the following line to see the error:
    // std::cout << sensor_distance << '\n';

    return 0;
}
