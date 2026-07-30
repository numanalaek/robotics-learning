// ============================================================
// Program 06d: For Loop with Array
// Description: Using for loop to read 5 ultrasonic sensors
//             and display their values.
// Concepts  : - Array: collection of data with index 0..n-1
//             - Array access with sensors[i]
//             - i is the index, sensors[i] is the value
// ============================================================

#include <iostream>

int main()
{
    // Array with 5 distance sensor elements (cm)
    int ultrasonic[5] = {120, 98, 150, 110, 95};

    // Loop to read all sensors
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Sensor "
                  << i
                  << " = "
                  << ultrasonic[i]
                  << " cm\n";
    }

    return 0;
}
