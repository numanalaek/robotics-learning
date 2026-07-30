// ============================================================
// Program 02: Variables and Data Types
// Description: Declaring and displaying various data types
//             commonly used in robot programming.
// Concepts  : - Various data types: int, double, float, bool,
//               char, std::string
//             - constexpr for compile-time constants
//             - auto for automatic type deduction
//             - std::setw for formatting output
//             - Ternary operator (?:) for simple conditions
// ============================================================

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    // ----- DECLARING VARIABLES WITH VARIOUS DATA TYPES -----
    std::string robot_name = "NUIN-AMR-01";  // string: text
    int robot_id = 1;                         // int: integer
    int battery = 100;                        // int: battery percentage
    double voltage = 24.6;                    // double: double precision decimal
    float speed = 1.25f;                      // float: single precision decimal
    bool obstacle = false;                    // bool: true/false
    char command = 'W';                       // char: single character

    // constexpr: fixed value known at compile time
    constexpr int wheel_count = 2;
    constexpr double MAX_PAYLOAD = 500.0;

    // auto: compiler determines type automatically
    const auto software_version = std::string("v1.0.0");

    // Ternary operator: inline if in one line
    auto obstacle_str = obstacle ? "Yes" : "No";

    // ----- PRINT ROBOT INFORMATION -----
    std::cout << "==============================" << '\n';
    std::cout << "NUIN Autonomous Mobile Robot" << '\n';
    std::cout << "==============================" << '\n';
    std::cout << '\n';

    // std::left: left align, std::fixed: fixed decimal format
    // std::setw(18): set column width to 18 characters
    std::cout << std::left;
    std::cout << std::fixed;
    std::cout << std::setw(18) << "Robot Name" << ": " << robot_name << '\n';
    std::cout << std::setw(18) << "Robot ID" << ": " << robot_id << '\n';
    std::cout << std::setw(18) << "Battery" << ": " << battery << " %" << '\n';
    std::cout << std::setw(18) << "Voltage" << ": " << std::setprecision(1) << voltage << " V" << '\n';
    std::cout << std::setw(18) << "Speed" << ": " << std::setprecision(2) << speed << " m/s" << '\n';
    std::cout << std::setw(18) << "Obstacle" << ": " << obstacle_str << '\n';
    std::cout << std::setw(18) << "Command" << ": " << command << '\n';
    std::cout << std::setw(18) << "Wheel Count" << ": " << wheel_count << '\n';
    std::cout << std::setw(18) << "Max Payload" << ": " << std::setprecision(1) << MAX_PAYLOAD << " kg" << '\n';
    std::cout << std::setw(18) << "Software Version" << ": " << software_version << std::endl;

    return 0;
}
