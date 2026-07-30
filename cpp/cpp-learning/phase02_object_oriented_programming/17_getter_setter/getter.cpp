// ============================================================
// getter.cpp — Getter (read-only access)
// ============================================================
// Compile & run:
//   g++ getter.cpp -o getter && ./getter
// ============================================================

#include <iostream>

// --- Data structs (small objects → return by value) ----------

struct Battery // small: int + double
{
    int percent;
    double voltage;
};

struct Velocity // small: double + double
{
    double linear;
    double angular;
};

// --- Robot class with getters only (no setters) --------------

class Robot
{
private:
    Battery battery_;   // trailing underscore _
    Velocity velocity_; // distinguishes member from parameter

public:
    Robot()
        : battery_{100, 24.5}, velocity_{0.5, 0.0}
    {
    }

    // Getter — return by value because type is small.
    // const → function does not modify class members.
    Battery getBattery() const
    {
        return battery_; // small copy, as efficient as reference
    }

    Velocity getVelocity() const
    {
        return velocity_;
    }
};

// --- main: caller -------------------------------------------------

int main()
{
    Robot robot;

    // const auto → snapshot, will not be modified
    // (indicates that we are only reading data)
    const auto battery = robot.getBattery();
    const auto velocity = robot.getVelocity();

    std::cout
        << "Battery : "
        << battery.percent
        << "% @ "
        << battery.voltage
        << " V\n";

    std::cout
        << "Velocity: linear="
        << velocity.linear
        << " m/s, angular="
        << velocity.angular
        << " rad/s\n";
}
