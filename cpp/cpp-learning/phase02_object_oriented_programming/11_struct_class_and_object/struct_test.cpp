// ============================================================
// Program 11c: Struct Test — Latihan Dasar
// Deskripsi : Latihan sederhana membuat struct Robot dengan
//             3 member dan satu object.
// Konsep    : - struct minimal: id, battery, voltage
//             - Membuat object lalu mengisi data member
//             - Menampilkan data dengan std::cout
// ============================================================

#include <iostream>

struct Robot
{
    int id;
    int battery;
    double voltage;
};

int main()
{
    Robot robot1;

    robot1.id = 1;
    robot1.battery = 100;
    robot1.voltage = 24.0;

    std::cout << "Robot ID : " << robot1.id << '\n';
    std::cout << "Battery  : " << robot1.battery << "%\n";
    std::cout << "Voltage  : " << robot1.voltage << " V\n";

    return 0;
}
