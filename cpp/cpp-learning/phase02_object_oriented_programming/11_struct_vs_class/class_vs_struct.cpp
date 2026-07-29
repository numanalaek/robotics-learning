// ============================================================
// Program 11d: class vs struct
// Deskripsi : Membandingkan struct dan class secara langsung.
//             Satu-satunya perbedaan: struct default public,
//             class default private.
// Konsep    : - struct Robot  -> semua member public (default)
//             - class Robot   -> semua member private (default)
//               sehingga perlu ditambahkan public: eksplisit
//             - Keduanya identik dalam fitur (bisa punya
//               constructor, method, dll.)
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

// --- CLASS (default: private, perlu public:) ---
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
    // Struct — semua member bisa diakses langsung
    RobotStruct robot1;
    robot1.id = 1;
    robot1.name = "NUIN-AMR-01";
    robot1.battery = 85;
    robot1.voltage = 24.5;

    // Class — member bisa diakses karena public:
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
