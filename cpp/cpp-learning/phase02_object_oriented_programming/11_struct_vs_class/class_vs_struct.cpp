// ============================================================
// Program 11d: class vs struct
// Description: Comparing struct and class directly.
//             The only difference: struct defaults to public,
//             class defaults to private.
// Concepts  : - struct Robot  -> all members public (default)
//             - class Robot   -> all members private (default)
//               so explicit public: must be added
//             - Both are identical in features (can have
//               constructors, methods, etc.)
// ============================================================

#include <iostream>
#include <string>

// --- STRUCT (default: public) ---
struct RobotStruct
{
    int id;
    std::string name;
    int battery;
    double voltage;
};

// --- CLASS (default: private, needs public:) ---
class RobotClass
{
public:
    int id;
    std::string name;
    int battery;
    double voltage;
};

int main()
{
    // Struct — all members can be accessed directly
    RobotStruct robot1;
    robot1.id = 1;
    robot1.name = "NUIN-AMR-01";
    robot1.battery = 85;
    robot1.voltage = 24.5;

    // Class — members can be accessed because of public:
    RobotClass robot2;
    robot2.id = 2;
    robot2.name = "NUIN-AMR-02";
    robot2.battery = 72;
    robot2.voltage = 23.8;

    std::cout << "=== struct Robot ===\n";
    std::cout << "  ID      : " << robot1.id << "\n";
    std::cout << "  Name    : " << robot1.name << "\n";
    std::cout << "  Battery : " << robot1.battery << "%\n";
    std::cout << "  Voltage : " << robot1.voltage << " V\n\n";

    std::cout << "=== class Robot ===\n";
    std::cout << "  ID      : " << robot2.id << "\n";
    std::cout << "  Name    : " << robot2.name << "\n";
    std::cout << "  Battery : " << robot2.battery << "%\n";
    std::cout << "  Voltage : " << robot2.voltage << " V\n";

    return 0;
}
