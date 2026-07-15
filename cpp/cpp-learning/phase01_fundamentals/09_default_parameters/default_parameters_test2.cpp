// ============================================================
// Program 09c: Default Parameter - Gerak Robot
// Deskripsi : Fungsi moveRobot dengan 2 default parameter.
// Konsep    : - moveRobot()       -> distance=1, speed=1.0
//             - moveRobot(5)      -> distance=5, speed=1.0
//             - moveRobot(5, 1.8) -> distance=5, speed=1.8
//             - Urutan parameter default harus dari kanan
// ============================================================

#include <iostream>

void moveRobot(
    int distance = 1,
    double speed = 1.0)
{
    std::cout << "Distance : " << distance << " m\n";
    std::cout << "Speed    : " << speed << " m/s\n";
}

int main()
{
    moveRobot();        // Semua default
    std::cout << '\n';
    moveRobot(5);       // distance=5, speed default
    std::cout << '\n';
    moveRobot(5, 1.8);  // Semua diisi
}
