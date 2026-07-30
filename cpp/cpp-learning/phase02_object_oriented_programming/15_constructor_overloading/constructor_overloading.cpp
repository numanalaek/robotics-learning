// ============================================================
// Program 1 — Constructor Overloading
// ============================================================
// Compile & run:
//   g++ constructor_overloading.cpp -o constructor_overloading
//   ./constructor_overloading
// ============================================================

#include <iostream>   // for std::cout
#include <string>     // for std::string

// ============================================================
// Class Robot — has 4 constructors with different parameters
// ============================================================
class Robot
{
private:
    int battery;          // member variable: battery level
    double voltage;       // member variable: voltage
    std::string mode;     // member variable: operating mode

public:
    // --- Constructor 1: no parameters ---
    // Used when: Robot robot1;
    // All values use defaults
    Robot()
        : battery(100),     // battery = 100%
          voltage(24.5),    // voltage = 24.5 V
          mode("READY")     // mode = READY
    {
    }

    // --- Constructor 2: 1 parameter (int) ---
    // Used when: Robot robot2(80);
    // battery is set from argument, rest are default
    Robot(int battery_)
        : battery(battery_),  // battery = argument value
          voltage(24.5),      // voltage = default
          mode("READY")       // mode = default
    {
    }

    // --- Constructor 3: 2 parameters (int, double) ---
    // Used when: Robot robot3(75, 24.1);
    // battery & voltage are set, mode is default
    Robot(int battery_,
          double voltage_)
        : battery(battery_),   // battery = argument value
          voltage(voltage_),   // voltage = argument value
          mode("READY")        // mode = default
    {
    }

    // --- Constructor 4: 3 parameters (int, double, string) ---
    // Used when: Robot robot4(60, 23.8, "AUTO");
    // All members are set from arguments
    Robot(int battery_,
          double voltage_,
          const std::string &mode_)
        : battery(battery_),   // battery = argument value
          voltage(voltage_),   // voltage = argument value
          mode(mode_)          // mode = argument value
    {
    }

    // Display robot status
    void printStatus() const
    {
        std::cout
            << "Battery : " << battery << "%\n"
            << "Voltage : " << voltage << " V\n"
            << "Mode    : " << mode << "\n\n";
    }
};

// ============================================================
// main() — proves the compiler selects the correct constructor
// ============================================================
int main()
{
    // Creating 4 objects, each with a different constructor
    Robot robot1;                  // memanggil Robot()
    Robot robot2(80);              // memanggil Robot(int)
    Robot robot3(75, 24.1);        // memanggil Robot(int, double)
    Robot robot4(60, 23.8, "AUTO");// memanggil Robot(int, double, string)

    // Print all robot statuses
    robot1.printStatus();
    robot2.printStatus();
    robot3.printStatus();
    robot4.printStatus();

    return 0;
}
// ============================================================
// OUTPUT:
// Battery : 100%
// Voltage : 24.5 V
// Mode    : READY
//
// Battery : 80%
// Voltage : 24.5 V
// Mode    : READY
//
// Battery : 75%
// Voltage : 24.1 V
// Mode    : READY
//
// Battery : 60%
// Voltage : 23.8 V
// Mode    : AUTO
// ============================================================
