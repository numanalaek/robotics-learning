// ============================================================
// Program 11a: Struct Robot
// Deskripsi : Mendefinisikan struct Robot dan membuat dua
//             object robot1 dan robot2.
// Konsep    : - struct adalah blueprint/tipe data bentukan
//             - Semua member struct default-nya public
//             - Robot robot1; adalah object nyata dari struct
//             - robot1.battery mengakses data member object
//             - Setiap object punya salinan data sendiri
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
