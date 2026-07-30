// ============================================================
// object_copy.cpp — Copy object (not a reference)
// ============================================================
// Compile & run:
//   g++ object_copy.cpp -o object_copy && ./object_copy
// ============================================================

#include <iostream>

class Robot
{
public:
    int battery;
    double voltage;
    double velocity;
};

// --- main: proving Robot robot2 = robot1 is COPY
//
//   Robot robot1;
//   robot1.battery = 90;
//
//   Robot robot2 = robot1;    ← COPY, not a reference
//   robot2.battery = 50;
//
//   robot1.battery = 90  (unchanged)
//   robot2.battery = 50  (independent)

int main()
{
    Robot robot1;
    robot1.battery = 90;
    robot1.voltage = 24.5;
    robot1.velocity = 0.5;

    // Robot robot2 = robot1;  not a reference!
    // This creates a NEW object with the SAME values
    // Copy Initialization
    // All members (battery, voltage, velocity)
    // are copied from robot1 to robot2.
    Robot robot2 = robot1;

    // Change robot2 — robot1 is not affected
    robot2.battery = 50;
    robot2.voltage = 12.0;
    robot2.velocity = 1.2;

    std::cout
        << "Robot1\n"
        << "Battery : " << robot1.battery << '\n'
        << "Voltage : " << robot1.voltage << '\n'
        << "Velocity: " << robot1.velocity << "\n\n";

    std::cout
        << "Robot2\n"
        << "Battery : " << robot2.battery << '\n'
        << "Voltage : " << robot2.voltage << '\n'
        << "Velocity: " << robot2.velocity << '\n';

    std::cout
        << "\n&robot1 = " << &robot1 << '\n'
        << "&robot2 = " << &robot2 << '\n'
        << "(alamat berbeda -> object berbeda, bukan reference)\n";
}
