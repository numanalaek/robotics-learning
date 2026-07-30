// ============================================================
// Program 10d: Lifetime — Object Life Span
// Description: Shows the order of creation (constructor) and
//             destruction (destructor) of Robot objects in various
//             scopes: global, function, and block.
// Concepts  : - Global -> created first, destroyed last
//             - Block  -> created at { }, destroyed at }
//             - LIFO   -> the last object created will
//               be destroyed first
//             - Observe the order of "created" and
//               "destroyed" output to understand lifetime
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
