// ============================================================
// Program 11c: Struct Test — Basic Exercise
// Description: Simple exercise creating a Robot struct with
//             3 members and one object.
// Concepts  : - minimal struct: id, battery, voltage
//             - Creating an object then filling data members
//             - Displaying data with std::cout
// ============================================================

#include <iostream>

struct Robot
{
    int id;
    int battery;
    double voltage;
};

int main()
{
    Robot robot1;

    robot1.id = 1;
    robot1.battery = 100;
    robot1.voltage = 24.0;

    std::cout << "Robot ID : " << robot1.id << '\n';
    std::cout << "Battery  : " << robot1.battery << "%\n";
    std::cout << "Voltage  : " << robot1.voltage << " V\n";

    return 0;
}
