// ============================================================
// Program 12: Constructor
// Description: Demonstrates constructor — a special function
//             that is automatically called when an object is created.
// Concepts  : - Constructor is called automatically
//             - Constructor name = class name
//             - Has no return type (not void)
//             - Used for initializing data members
//             - Member initializer list (: battery(100), ...)
//             - struct for grouping data (Pose)
// ============================================================
//
// Compile  : g++ -std=c++11 -o constructor constructor.cpp
// Run      : ./constructor
// One-step : g++ -std=c++11 -o constructor constructor.cpp && ./constructor

#include <iostream>
#include <string>

struct Pose
{
    double x;
    double y;
};

class Robot
{
private:
    int battery;
    double voltage;
    std::string mode;
    Pose pose;

public:
    Robot()
        : battery(100),
          voltage(24.5),
          mode("READY"),
          pose{0.0, 0.0}
    {
    }

    void printStatus() const
    {
        std::cout
            << "Robot Status:\n"
            << "Battery : " << battery << "%\n"
            << "Voltage : " << voltage << " V\n"
            << "Mode    : " << mode << "\n"
            << "Pose    : (" << pose.x << ", "
            << pose.y << ")\n";
    }
};

int main()
{
    Robot robot;

    robot.printStatus();

    return 0;
}
