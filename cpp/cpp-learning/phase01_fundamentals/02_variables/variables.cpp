#include <iostream>
#include <string>
#include <iomanip>
int main()
{
    std::string robot_name = "NUIN-AMR-01";
    int robot_id = 1;
    int battery = 100;
    double voltage = 24.6;
    float speed = 1.25f;
    bool obstacle = false;
    char command = 'W';
    constexpr int wheel_count = 2;
    constexpr double MAX_PAYLOAD = 500.0;
    const auto software_version = std::string("v1.0.0");
    auto obstacle_str = obstacle ? "Yes" : "No";

    std::cout << "==============================" << '\n';
    std::cout << "NUIN Autonomous Mobile Robot" << '\n';
    std::cout << "==============================" << '\n';
    std::cout << '\n';

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
