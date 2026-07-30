// ============================================================
// Program 2 — Constructor Overloading with struct Pose
// ============================================================
// Compile & run:
//   g++ constructor_overloading2.cpp -o constructor_overloading2
//   ./constructor_overloading2
// ============================================================

#include <iostream> // for std::cout

// ============================================================
// Struct Pose — represents a 2D position (x, y)
// ============================================================
struct Pose
{
    double x;
    double y;
};

// ============================================================
// Class Robot — has Pose member + 3 constructors
// ============================================================
class Robot
{
private:
    int battery; // battery level (%)
    Pose pose;   // robot position (x, y)

public:
    // --- Constructor 1: no parameters ---
    // Used when: Robot robot1;
    // All values default: battery=100%, pose=(0,0)
    Robot()
        : battery(100),  // battery = 100%
          pose{0.0, 0.0} // pose = (0, 0)
    {
    }

    // --- Constructor 2: 1 parameter (int) ---
    // Used when: Robot robot2(80);
    // battery set from argument, pose stays default (0,0)
    Robot(int battery_)
        : battery(battery_), // battery = argument value
          pose{0.0, 0.0}     // pose = default (0, 0)
    {
    }

    // --- Constructor 3: 2 parameters (int, Pose) ---
    // Used when: Robot robot3(75, {2.5, 3.0});
    // battery & pose are set from arguments
    Robot(int battery_,
          Pose robot_pose)
        : battery(battery_), // battery = argument value
          pose(robot_pose)   // pose = argument value
    {
    }

    // Display robot status
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
// main() — proves the compiler selects the correct constructor
// ============================================================
int main()
{
    // Creating 5 objects with 3 different constructors
    Robot robot1;                 // memanggil Robot()
    Robot robot2(80);             // memanggil Robot(int)
    Robot robot3(75, {2.5, 3.0}); // memanggil Robot(int, Pose)
    Robot robot4(60, {1.5, 4.2}); // memanggil Robot(int, Pose)
    Robot robot5(90);             // memanggil Robot(int)

    // Print all robot statuses
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
