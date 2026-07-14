#include <iostream>

void setSpeed(int speed)
{
    std::cout << "Speed = "
              << speed
              << " m/s (integer)\n";
}

void setSpeed(double speed)
{
    std::cout << "Speed = "
              << speed
              << " m/s (double)\n";
}

int main()
{
    setSpeed(1);
    setSpeed(1.25);
}
