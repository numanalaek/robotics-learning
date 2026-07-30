// import iostream library for standard input/output (cin, cout)
#include <iostream>
// import string library for std::string data type
#include <string>

// defines the Robot class
class Robot
{
    // private section: can only be accessed from within the class
private:
    int id;           // stores unique robot ID
    int battery;      // stores battery percentage (0-100)
    std::string mode; // stores robot operating mode

    // public section: can be accessed from outside the class
public:
    // --- PARAMETERIZED CONSTRUCTOR ---
    // parameter name uses "robot_" prefix to distinguish
    // from data member names (though not required, can be different)
    Robot(
        int robot_id,
        int robot_battery,
        const std::string &robot_mode)
        // initializer list: initializes data members with parameter values
        : id(robot_id),
          battery(robot_battery),
          mode(robot_mode)
    {
        // constructor body is empty because initialization is already
        // handled by the initializer list
    }

    // method to display robot status in one line
    // const => this method does not modify data members
    void printStatus() const
    {
        // displays id, battery, and mode with structured format
        std::cout
            << "Robot " << id
            << " | Battery "
            << battery
            << "% | "
            << mode
            << '\n';
    }
};

// main function of the program
int main()
{
    // --- CREATING MULTIPLE OBJECTS WITH PARAMETERIZED CONSTRUCTOR ---
    // each object can have different initialization values

    // creates first robot with ID 1, battery 95%, mode AUTO
    Robot robot1(
        1,
        95,
        "AUTO");

    // creates second robot with ID 2, battery 60%, mode MANUAL
    Robot robot2(
        2,
        60,
        "MANUAL");

    // calls the printStatus() method for each robot
    robot1.printStatus();
    robot2.printStatus();

    return 0;
}
