#include <iostream>

// ============================================================
// ENCAPSULATION — hiding data members from direct access
// ============================================================

class Robot
{
    // private: data members can only be accessed from within the class
private:
    int battery;

    // public: member function as a bridge to the outside world
public:
    // Constructor — initializes battery with initial value 100
    Robot()
        : battery(100)
    {
    }

    // const member function — does not modify data members
    void printStatus() const
    {
        std::cout
            << "Battery : "
            << battery
            << "%\n";
    }
};

int main()
{
    // Creating Robot object — constructor will call Robot()
    Robot robot;

    // If the following line is uncommented, it will error:
    //   'int Robot::battery' is private within this context
    // because battery is private and cannot be accessed from outside the class.
    // robot.battery = 50;

    // The only way to read battery is via public member function
    robot.printStatus();

    return 0;
}
