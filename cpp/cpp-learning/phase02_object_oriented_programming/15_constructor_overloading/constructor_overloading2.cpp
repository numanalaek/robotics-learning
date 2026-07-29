// ============================================================
// Program 2 — Constructor Overloading dengan struct Pose
// ============================================================
// Compile & run:
//   g++ constructor_overloading2.cpp -o constructor_overloading2
//   ./constructor_overloading2
// ============================================================

#include <iostream> // untuk std::cout

// ============================================================
// Struct Pose — merepresentasikan posisi 2D (x, y)
// ============================================================
struct Pose
{
    double x;
    double y;
};

// ============================================================
// Class Robot — memiliki member Pose + 3 constructor
// ============================================================
class Robot
{
private:
    int battery; // level battery (%)
    Pose pose;   // posisi robot (x, y)

public:
    // --- Constructor 1: tanpa parameter ---
    // Digunakan saat: Robot robot1;
    // Semua nilai default: battery=100%, pose=(0,0)
    Robot()
        : battery(100),  // battery = 100%
          pose{0.0, 0.0} // pose = (0, 0)
    {
    }

    // --- Constructor 2: 1 parameter (int) ---
    // Digunakan saat: Robot robot2(80);
    // battery diatur dari argumen, pose tetap default (0,0)
    Robot(int battery_)
        : battery(battery_), // battery = nilai argumen
          pose{0.0, 0.0}     // pose = default (0, 0)
    {
    }

    // --- Constructor 3: 2 parameter (int, Pose) ---
    // Digunakan saat: Robot robot3(75, {2.5, 3.0});
    // battery & pose diatur dari argumen
    Robot(int battery_,
          Pose robot_pose)
        : battery(battery_), // battery = nilai argumen
          pose(robot_pose)   // pose = nilai argumen
    {
    }

    // Menampilkan status robot
    void printStatus() const
    {
        std::cout
            << "Battery : " << battery << "%\n"
            << "Pose    : (" << pose.x
            << ", "
            << pose.y
            << ")\n\n";
    }
};

// ============================================================
// main() — membuktikan compiler memilih constructor yg tepat
// ============================================================
int main()
{
    // Membuat 5 object dengan 3 constructor berbeda
    Robot robot1;                 // memanggil Robot()
    Robot robot2(80);             // memanggil Robot(int)
    Robot robot3(75, {2.5, 3.0}); // memanggil Robot(int, Pose)
    Robot robot4(60, {1.5, 4.2}); // memanggil Robot(int, Pose)
    Robot robot5(90);             // memanggil Robot(int)

    // Cetak status semua robot
    robot1.printStatus();
    robot2.printStatus();
    robot3.printStatus();
    robot4.printStatus();
    robot5.printStatus();

    return 0;
}
// ============================================================
// OUTPUT:
// Battery : 100%
// Pose    : (0, 0)
//
// Battery : 80%
// Pose    : (0, 0)
//
// Battery : 75%
// Pose    : (2.5, 3)
//
// Battery : 60%
// Pose    : (1.5, 4.2)
//
// Battery : 90%
// Pose    : (0, 0)
// ============================================================
