#include <iostream>

// ============================================================
// STRUCT COMPOSITION + ENCAPSULATION
// ============================================================
// struct: groups related data into a single unit
// (similar to class, but default access is public)

// Battery — stores robot battery status
struct Battery
{
    int percent;    // battery percentage (0–100)
    double voltage; // battery voltage in Volts
};

// Velocity — stores robot velocity (linear & angular)
struct Velocity
{
    double linear;  // linear velocity (m/s)
    double angular; // angular velocity (rad/s)
};

// ============================================================
// CLASS ROBOT — hides internal details (encapsulation)
// ============================================================
// private:   data members — cannot be accessed directly from outside
// public:    member functions — interface to the outside world
// trailing underscore (_) on member names distinguishes them from
// constructor parameters (ROS 2 / modern C++ style)
class Robot
{
private:
    Battery battery_;    // battery data (struct)
    Velocity velocity_;  // velocity data (struct)
    bool emergency_;     // emergency status

public:
    // Default constructor — all data filled with default values
    Robot()
        : battery_{100, 12.5},    // battery 100%, 12.5V
          velocity_{0.0, 0.0},    // stationary
          emergency_(false)       // not emergency
    {
    }

    // Parameterized constructor — receives struct directly (const reference)
    //   const Battery& battery  → parameter (without _)
    //   battery_                → data member (with _)
    // With the _ convention, parameter names can be the same as member names
    // without causing ambiguity.
    Robot(const Battery &battery, const Velocity &velocity, bool emergency)
        : battery_(battery),     // copy from parameter to member
          velocity_(velocity),
          emergency_(emergency)
    {
    }

    // const member function — does not modify data members
    void printStatus() const
    {
        // Access data member via dot operator (.)
        std::cout
            << "Battery : " << battery_.percent << "% @ " << battery_.voltage << " V\n"
            << "Velocity: " << velocity_.linear << " m/s linear, " << velocity_.angular << " rad/s angular\n"
            << "Emergency: " << (emergency_ ? "ACTIVE" : "NONE") << "\n";
    }
};

// ============================================================
// MAIN — program entry point
// ============================================================
int main()
{
    // Creating Robot object using parameterized constructor.
    // Aggregate initialization {} creates temporary Battery and Velocity
    //   {100, 24.5}  → Battery{percent=100, voltage=24.5}
    //   {0.0, 0.0}   → Velocity{linear=0.0, angular=0.0}
    // false          → emergency=false
    // Robot 1: AGV 24V, stationary
    Robot robot1({100, 24.5}, {0.0, 0.0}, false);

    // Robot 2: Forklift AGV 48V, moving at 1.5 m/s
    Robot robot2({85, 48.0}, {1.5, 0.0}, false);

    // Calling public member function to view status
    std::cout << "=== Robot 1 ===\n";
    robot1.printStatus();

    std::cout << "\n=== Robot 2 ===\n";
    robot2.printStatus();

    return 0;
}
