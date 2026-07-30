// ============================================================
// object.cpp — Object is a real instance of a class
// ============================================================
// Compile & run:
//   g++ object.cpp -o object && ./object
// ============================================================

#include <iostream>

// --- Class (blueprint / design) -----------------------------

class Robot
{
public:
    int battery;
    double voltage;
    double velocity;
};

// --- main: multiple objects, each with its own memory
//
//   Robot class  ← blueprint
//      │
//   ┌──┴──┐
//   ▼     ▼
// robot1 robot2
//
// All have members: battery, voltage, velocity
// But their values are DIFFERENT — each has its own memory

int main()
{
    // --- Two objects from the same class --------------------
    Robot robot1;
    Robot robot2;

    // Fill each with their own values (do not affect each other)
    robot1.battery = 90;
    robot1.voltage = 24.5;
    robot1.velocity = 0.5;

    robot2.battery = 40;
    robot2.voltage = 12.0;
    robot2.velocity = 1.2;

    std::cout
        << "robot1\n"
        << "  &robot1         = " << &robot1 << '\n'
        << "  &robot1.battery = " << &robot1.battery << '\n'
        << "  Battery         = " << robot1.battery << "%\n"
        << "  Voltage         = " << robot1.voltage << " V\n"
        << "  Velocity        = " << robot1.velocity << " m/s\n"
        << "\n"
        << "robot2\n"
        << "  &robot2         = " << &robot2 << '\n'
        << "  &robot2.battery = " << &robot2.battery << '\n'
        << "  Battery         = " << robot2.battery << "%\n"
        << "  Voltage         = " << robot2.voltage << " V\n"
        << "  Velocity        = " << robot2.velocity << " m/s\n";

    // Proof that changing robot1 does not affect robot2
    robot1.battery = 0;

    std::cout
        << "\nSetelah robot1.battery = 0:\n"
        << "  robot1.battery = " << robot1.battery << "%\n"
        << "  robot2.battery = " << robot2.battery << "%\n"
        << "  (robot2 tidak terpengaruh)\n";
}
