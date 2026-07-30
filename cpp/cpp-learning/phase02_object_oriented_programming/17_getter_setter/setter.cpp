// ============================================================
// setter.cpp — Getter + Setter with validation
// ============================================================
// Compile & run:
//   g++ setter.cpp -o setter && ./setter
// ============================================================

#include <iostream>
#include <stdexcept>

// --- Data structs ---------------------------------------------

struct Battery
{
    int percent;
    double voltage;
};

struct Velocity
{
    double linear;
    double angular;
};

// --- Robot class with getter AND setter -----------------------

class Robot
{
private:
    Battery battery_;
    Velocity velocity_;

public:
    Robot()
        : battery_{100, 24.5}, velocity_{0.5, 0.0}
    {
    }

    // --- Getter (by value — small type) -------------------------
    Battery getBattery() const
    {
        return battery_;
    }

    Velocity getVelocity() const
    {
        return velocity_;
    }

    // --- Setter (by const reference — complete struct) -----------

    // Setter receives the whole struct, not individual parameters.
    // Validation is done BEFORE assignment.
    void setBattery(const Battery &battery)
    {
        // Validation: percent 0–100
        if (battery.percent < 0 || battery.percent > 100)
        {
            throw std::out_of_range{"Battery percent must be 0–100"};
        }
        // Validation: voltage > 0
        if (battery.voltage <= 0.0)
        {
            throw std::out_of_range{"Voltage must be > 0"};
        }
        battery_ = battery; // safe → store
    }

    void setVelocity(const Velocity &velocity)
    {
        // Validation: linear >= 0
        if (velocity.linear < 0.0)
        {
            throw std::out_of_range{"Linear velocity must not be negative"};
        }
        // Validation: angular within range
        if (velocity.angular < -10.0 || velocity.angular > 10.0)
        {
            throw std::out_of_range{"Angular velocity must be in range -10.0 to 10.0 rad/s"};
        }
        velocity_ = velocity;
    }
};

// --- main: caller -------------------------------------------------

int main()
{
    Robot robot;

    // Set via braced-init-list (C++11)
    // → similar to receiving a struct object from a ROS 2 message
    robot.setBattery({85, 23.8});
    robot.setVelocity({1.2, -2.5});

    // Get → const for snapshot
    const Battery battery = robot.getBattery();
    const Velocity velocity = robot.getVelocity();

    std::cout << "Battery : " << battery.percent << "% @ " << battery.voltage << " V\n";
    std::cout << "Velocity: linear=" << velocity.linear << " m/s, angular=" << velocity.angular << " rad/s\n";

    // --- Validation test: invalid values -----------------------------

    try
    {
        robot.setBattery({150, 12.0}); // percent > 100 → throw
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Validation OK : " << e.what() << "\n";
    }
}
