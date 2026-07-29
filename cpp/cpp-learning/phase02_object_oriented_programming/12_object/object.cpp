// ============================================================
// object.cpp — Object adalah instance nyata dari class
// ============================================================
// Compile & run:
//   g++ object.cpp -o object && ./object
// ============================================================

#include <iostream>

// --- Class (blueprint / desain) -----------------------------

class Robot
{
public:
    int battery;
    double voltage;
    double velocity;
};

// --- main: multiple object, masing-masing punya memori sendiri
//
//   Robot class  ← blueprint
//      │
//   ┌──┴──┐
//   ▼     ▼
// robot1 robot2
//
// Semua punya member: battery, voltage, velocity
// Tapi nilainya BEBEDA — masing-masing punya memori sendiri

int main()
{
    // --- Dua object dari class yang sama --------------------
    Robot robot1;
    Robot robot2;

    // Isi nilai masing-masing (tidak saling mempengaruhi)
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

    // Bukti perubahan robot1 tidak mempengaruhi robot2
    robot1.battery = 0;

    std::cout
        << "\nSetelah robot1.battery = 0:\n"
        << "  robot1.battery = " << robot1.battery << "%\n"
        << "  robot2.battery = " << robot2.battery << "%\n"
        << "  (robot2 tidak terpengaruh)\n";
}
