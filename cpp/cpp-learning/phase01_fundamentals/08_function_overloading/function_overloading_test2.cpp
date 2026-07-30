// ============================================================
// Program 08c: Overloading - Different Parameter Types
// Description: Overloading with different parameter types
//             (int vs double). The compiler selects based on
//             the given argument types.
// Concepts  : - setSpeed(int)    : called if argument is integer
//             - setSpeed(double) : called if argument is decimal
//             - Parameter types can be int, double, float, etc.
// ============================================================

#include <iostream>

// Version for integer speed
void setSpeed(int speed)
{
    std::cout << "Speed = " << speed << " m/s (integer)\n";
}

// Version for decimal speed
void setSpeed(double speed)
{
    std::cout << "Speed = " << speed << " m/s (double)\n";
}

int main()
{
    setSpeed(1);      // 1 is int -> call int version
    setSpeed(1.25);   // 1.25 is double -> call double version
}
