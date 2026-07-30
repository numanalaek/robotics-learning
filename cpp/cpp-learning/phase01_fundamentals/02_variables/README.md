# 02 — Variables

Declaring and using various C++ data types in a robot context.

## Four Important Things about Variables

| # | Concept | Example |
|---|--------|--------|
| 1 | Every variable has a **data type** | `int battery = 100;` |
| 2 | `std::string` for text | `std::string name = "Robot";` |
| 3 | `constexpr` for compile-time constants | `constexpr int WHEELS = 2;` |
| 4 | `auto` deduces type automatically | `auto version = "v1.0";` |

## Code — `variables.cpp`

```cpp
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

    std::cout << "==============================\n";
    std::cout << "NUIN Autonomous Mobile Robot\n";
    std::cout << "==============================\n\n";

    std::cout << std::left;
    std::cout << std::fixed;
    std::cout << std::setw(18) << "Robot Name" << ": " << robot_name << '\n';
    std::cout << std::setw(18) << "Robot ID" << ": " << robot_id << '\n';
    std::cout << std::setw(18) << "Battery" << ": " << battery << " %\n";
    std::cout << std::setw(18) << "Voltage" << ": "
              << std::setprecision(1) << voltage << " V\n";
    std::cout << std::setw(18) << "Speed" << ": "
              << std::setprecision(2) << speed << " m/s\n";
    std::cout << std::setw(18) << "Obstacle" << ": " << obstacle_str << '\n';
    std::cout << std::setw(18) << "Command" << ": " << command << '\n';
    std::cout << std::setw(18) << "Wheel Count" << ": " << wheel_count << '\n';
    std::cout << std::setw(18) << "Max Payload" << ": "
              << std::setprecision(1) << MAX_PAYLOAD << " kg\n";
    std::cout << std::setw(18) << "Software Version" << ": "
              << software_version << std::endl;

    return 0;
}
```

## Output

```
==============================
NUIN Autonomous Mobile Robot
==============================

Robot Name        : NUIN-AMR-01
Robot ID          : 1
Battery           : 100 %
Voltage           : 24.6 V
Speed             : 1.25 m/s
Obstacle          : No
Command           : W
Wheel Count       : 2
Max Payload       : 500.0 kg
Software Version  : v1.0.0
```

## Data Types

| Type | Size | Robotics Example |
|------|--------|----------------|
| `int` | 4 bytes | Robot ID, wheel count, battery |
| `double` | 8 bytes | Voltage, GPS coordinates |
| `float` | 4 bytes | Speed, temperature |
| `bool` | 1 byte | Obstacle detection, emergency status |
| `char` | 1 byte | Movement command ('W', 'S', 'A', 'D') |
| `std::string` | dynamic | Robot name, software version |

## Command Line

```bash
g++ variables.cpp -o variables && ./variables
```

## Analogy

Variables are like **status boards on a robot dashboard** — each board stores one piece of information in a specific format.

| Dashboard Board | Type | Content |
|----------------|------|-----|
| Robot name | `string` | "NUIN-AMR-01" |
| Battery | `int` | 100 |
| Voltage | `double` | 24.6 |
| Speed | `float` | 1.25 |
| Obstacle | `bool` | false |

## Exercises

1. Add variable `int temperature = 45;` — print it with `std::setw`.
2. Change `obstacle` to `true` — what changes in the output?
3. Replace `constexpr` with `const` — does it still work?
4. Use `auto` for all variables — can they still be printed?
