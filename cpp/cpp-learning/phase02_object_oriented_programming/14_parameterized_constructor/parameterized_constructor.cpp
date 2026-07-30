// import iostream library for standard input/output (cin, cout)
#include <iostream>
// import string library for std::string data type
#include <string>

// defines the Robot class
class Robot
{
// private section: can only be accessed from within the class
private:
    int battery;          // stores battery percentage (0-100)
    double voltage;       // stores voltage in volts
    std::string mode;     // stores robot operating mode

// public section: can be accessed from outside the class
public:
    // --- PARAMETERIZED CONSTRUCTOR ---
    // constructor with 3 parameters to initialize data members
    Robot(int battery_,
          double voltage_,
          const std::string &mode_)
        // initializer list: efficient way to initialize data members
        : battery(battery_),
          voltage(voltage_),
          mode(mode_)
    {
        // constructor body is empty because initialization was already done
        // by the initializer list above
    }

    // method to print robot status
    // const => this method does not modify data members
    void printStatus() const
    {
        // displays battery, voltage, and mode values to screen
        std::cout
            << "Battery : " << battery << "%\n"
            << "Voltage : " << voltage << " V\n"
            << "Mode    : " << mode << "\n";
    }
};

// main function of the program
int main()
{
    // creates a Robot object with parameterized constructor
    // values 85, 24.3, "AUTO" are sent to the constructor as arguments
    Robot robot(
        85,       // battery = 85%
        24.3,     // voltage = 24.3 V
        "AUTO");  // mode = "AUTO"

    // calls the printStatus() method to display robot data
    robot.printStatus();

    return 0;
}
