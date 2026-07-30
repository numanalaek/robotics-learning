// ============================================================
// Program 11a: Struct Robot
// Description: Defines a Robot struct and creates two
//              objects robot1 and robot2.
// Concepts  : - struct is a blueprint/custom data type
//             - All struct members are public by default
//             - Robot robot1; is a real object from the struct
//             - robot1.battery accesses the object's data member
//             - Each object has its own copy of data
// ============================================================

#include <iostream>
#include <string>

struct Robot
{
    int id;
    std::string name;
    int battery;
    double voltage;
};

int main()
{
    Robot robot1;
    robot1.id = 1;
    robot1.name = "NUIN-AMR-01";
    robot1.battery = 85;
    robot1.voltage = 24.5;

    Robot robot2;
    robot2.id = 2;
    robot2.name = "NUIN-AMR-02";
    robot2.battery = 72;
    robot2.voltage = 23.8;

    std::cout << "Robot 1:\n";
    std::cout << "  ID      : " << robot1.id << "\n";
    std::cout << "  Name    : " << robot1.name << "\n";
    std::cout << "  Battery : " << robot1.battery << "%\n";
    std::cout << "  Voltage : " << robot1.voltage << " V\n\n";

    std::cout << "Robot 2:\n";
    std::cout << "  ID      : " << robot2.id << "\n";
    std::cout << "  Name    : " << robot2.name << "\n";
    std::cout << "  Battery : " << robot2.battery << "%\n";
    std::cout << "  Voltage : " << robot2.voltage << " V\n";

    return 0;
}
