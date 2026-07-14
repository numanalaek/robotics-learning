#include <iomanip>
#include <iostream>

void robotStatus(
    int battery = 100,
    double voltage = 24.0,
    bool obstacle = false)
{
    std::cout << std::fixed << std::setprecision(1);

    std::cout
        << "Battery  : " << battery << "%\n"
        << "Voltage  : " << voltage << " V\n"
        << "Obstacle : "
        << (obstacle ? "YES" : "NO")
        << "\n\n";
}

int main()
{
    robotStatus();
    robotStatus(80);
    robotStatus(80, 23.5);
    robotStatus(80, 23.5, true);

    return 0;
}
