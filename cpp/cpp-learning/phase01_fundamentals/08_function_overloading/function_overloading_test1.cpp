// ============================================================
// Program 08b: Overloading - Robot Movement
// Description: move() function is overloaded for movement
//             without parameter (1 step) or with step count.
// Concepts  : - move()       : move forward 1 step (default)
//             - move(int)    : move forward n steps
//             - Same function name, different parameters
// ============================================================

#include <iostream>

// Version without parameter: move forward 1 step
void move()
{
    std::cout << "Robot moves forward 1 step\n";
}

// Version with parameter: move forward n steps
void move(int step)
{
    std::cout << "Robot moves forward " << step << " steps\n";
}

int main()
{
    move();     // Call version without parameter
    move(5);    // Call version with int parameter
}
