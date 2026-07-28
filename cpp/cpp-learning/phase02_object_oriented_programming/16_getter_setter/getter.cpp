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
    Velocity velocity_; // membedakan member vs parameter

public:
    Robot()
        : battery_{100, 24.5}, velocity_{0.5, 0.0}
    {
    }

    // Getter — return by value karena tipe kecil.
    // const → fungsi tidak mengubah member class.
    Battery getBattery() const
    {
        return battery_; // copy kecil, sama efisien dg reference
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

    // const auto → snapshot, tidak akan diubah
    // (tanda bahwa kita hanya membaca data)
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
