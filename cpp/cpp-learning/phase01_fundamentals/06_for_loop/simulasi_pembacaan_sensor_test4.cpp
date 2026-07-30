// ============================================================
// Program 06e: For Loop - Obstacle Detection
// Description: Reads 7 sensors and determines if there is
//             an obstacle based on distance < 100 cm.
// Concepts  : - if-else inside for loop
//             - Logic: if sensor[i] < 100 then OBSTACLE
//             - else then CLEAR (safe)
// ============================================================

#include <iostream>

int main()
{
    // Distance sensor array (cm)
    int ultrasonic[7] = {120, 98, 150, 110, 95, 70, 130};

    for (int i = 0; i < 7; i++)
    {
        // If distance < 100 cm, there is an obstacle
        if (ultrasonic[i] < 100)
        {
            std::cout << "Sensor " << i << " : OBSTACLE\n";
        }
        else
        {
            std::cout << "Sensor " << i << " : CLEAR\n";
        }
    }

    return 0;
}
