// ============================================================
// object_copy.cpp — Copy object (bukan reference)
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

// --- main: membuktikan Robot robot2 = robot1 adalah COPY
//
//   Robot robot1;
//   robot1.battery = 90;
//
//   Robot robot2 = robot1;    ← COPY, bukan reference
//   robot2.battery = 50;
//
//   robot1.battery = 90  (tidak berubah)
//   robot2.battery = 50  (berdiri sendiri)

int main()
{
    Robot robot1;
    robot1.battery = 90;
    robot1.voltage = 24.5;
    robot1.velocity = 0.5;

    // Robot robot2 = robot1;  bukan reference!
    // Ini membuat object BARU dengan nilai yang SAMA
    // Copy Initialization
    // Semua member (battery, voltage, velocity)
    // disalin (copied) dari robot1 ke robot2.
    Robot robot2 = robot1;

    // Ubah robot2 — robot1 tidak terpengaruh
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
