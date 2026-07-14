#include <iostream>

void moveRobot(
    int distance = 1,
    double speed = 1.0)
{
    std::cout << "Distance : "
              << distance
              << " m\n";

    std::cout << "Speed    : "
              << speed
              << " m/s\n";
}

int main()
{
    moveRobot();

    std::cout << '\n';

    moveRobot(5);

    std::cout << '\n';

    moveRobot(5, 1.8);
}
