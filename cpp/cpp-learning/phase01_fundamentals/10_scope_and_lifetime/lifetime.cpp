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
