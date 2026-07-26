// ============================================================
// Program 10d: Lifetime — Masa Hidup Objek
// Deskripsi : Menunjukkan urutan pembuatan (constructor) dan
//             penghancuran (destructor) objek Robot di berbagai
//             scope: global, fungsi, dan block.
// Konsep    : - Global -> dibuat pertama, dihancurkan terakhir
//             - Block  -> dibuat saat { }, dihancurkan saat }
//             - LIFO   -> objek yang dibuat terakhir akan
//               dihancurkan pertama
//             - Perhatikan urutan output "created" dan
//               "destroyed" untuk memahami lifetime
// ============================================================

#include <iostream>

struct Robot
{
    int id;
    const char* name;

    Robot(int robot_id, const char* n)
        : id(robot_id), name(n)
    {
        std::cout << name << " created\n";
    }

    ~Robot()
    {
        std::cout << name << " destroyed\n";
    }
};

Robot robot_id{1, "Robot ID"};

void robotFunction()
{
    Robot battery{100, "Battery"};

    std::cout << "Battery: " << battery.id << '\n';

    {
        Robot sensor_distance{45, "Sensor"};

        std::cout << "Sensor: " << sensor_distance.id << " cm\n";
    }
}

int main()
{
    std::cout << '\n';

    robotFunction();

    std::cout << '\n';

    return 0;
}
