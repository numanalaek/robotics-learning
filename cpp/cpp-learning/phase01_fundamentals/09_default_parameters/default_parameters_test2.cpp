// ============================================================
// Program 09c: Default Parameter - Robot Movement
// Description: moveRobot function with 2 default parameters.
// Concepts  : - moveRobot()       -> distance=1, speed=1.0
//             - moveRobot(5)      -> distance=5, speed=1.0
//             - moveRobot(5, 1.8) -> distance=5, speed=1.8
//             - Default parameter order must be from the right
// ============================================================

#include <iostream>

void moveRobot(
    int distance = 1,
    double speed = 1.0)
{
    std::cout << "Distance : " << distance << " m\n";
    std::cout << "Speed    : " << speed << " m/s\n";
}

int main()
{
    moveRobot();        // All defaults
    std::cout << '\n';
    moveRobot(5);       // distance=5, speed default
    std::cout << '\n';
    moveRobot(5, 1.8);  // All filled
}
