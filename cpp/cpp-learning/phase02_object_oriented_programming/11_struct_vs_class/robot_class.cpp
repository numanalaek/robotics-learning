// ============================================================
// Program 11b: Class Robot
// Description: Converting struct to class. The result is exactly
//             the same, but class requires explicit public:.
// Concepts  : - class is also a blueprint like struct
//             - Difference: class defaults to private, struct
//               defaults to public
//             - Without public:, members cannot be accessed
//               from outside the class
//             - Same usage: Robot robot1; robot1.id = ...;
// ============================================================

#include <iostream>
#include <string>

class Robot
{
public:
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
