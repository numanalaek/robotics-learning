// ============================================================
// Program 11e: class Test — Latihan Object
// Deskripsi : Latihan membuat class Robot dengan data member
//             dan mengaksesnya melalui object.
// Konsep    : - class adalah blueprint / tipe data
//             - Object adalah instance nyata dari class
//             - Setiap object punya salinan data member sendiri
//             - Member diakses dengan operator titik (.)
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
    robot1.id = 10;
    robot1.name = "NUIN-AMR-03";
    robot1.battery = 95;
    robot1.voltage = 24.8;

    Robot robot2;
    robot2.id = 20;
    robot2.name = "NUIN-AMR-04";
    robot2.battery = 60;
    robot2.voltage = 23.2;

    std::cout << "Robot " << robot1.id << " (" << robot1.name << ")\n";
    std::cout << "  Battery : " << robot1.battery << "%\n";
    std::cout << "  Voltage : " << robot1.voltage << " V\n\n";

    std::cout << "Robot " << robot2.id << " (" << robot2.name << ")\n";
    std::cout << "  Battery : " << robot2.battery << "%\n";
    std::cout << "  Voltage : " << robot2.voltage << " V\n\n";

    // Membuktikan setiap object punya data sendiri
    std::cout << "Setelah robot1 baterai dikurangi 10:\n";
    robot1.battery = robot1.battery - 10;
    std::cout << "  robot1 battery : " << robot1.battery << "%\n";
    std::cout << "  robot2 battery : " << robot2.battery << "%\n";
    std::cout << "  (robot2 tidak terpengaruh)\n";

    return 0;
}
