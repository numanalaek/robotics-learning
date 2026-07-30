// ============================================================
// Program 09a: Default Parameters
// Description: Function with default parameters so it can
//             be called with different numbers of arguments.
// Concepts  : - Default parameters are given in declaration/definition
//             - robotStatus()           -> all use defaults
//             - robotStatus(80)         -> battery=80, rest default
//             - robotStatus(80, 23.5)   -> battery & voltage filled
//             - robotStatus(80,23.5,true) -> all filled
//             - Defaults can only be on the rightmost parameters
// ============================================================

#include <iomanip>
#include <iostream>

// All parameters have default values
// Parameters with defaults must be on the rightmost side
void robotStatus(
    int battery = 100,
    double voltage = 24.0,
    bool obstacle = false)
{
    std::cout << std::fixed << std::setprecision(1);

    std::cout
        << "Battery  : " << battery << "%\n"
        << "Voltage  : " << voltage << " V\n"
        << "Obstacle : "
        << (obstacle ? "YES" : "NO")
        << "\n\n";
}

int main()
{
    // Various ways to call a function with default parameters
    robotStatus();                  // All defaults
    robotStatus(80);                // battery=80, voltage & obstacle default
    robotStatus(80, 23.5);          // battery=80, voltage=23.5
    robotStatus(80, 23.5, true);    // All filled

    return 0;
}
