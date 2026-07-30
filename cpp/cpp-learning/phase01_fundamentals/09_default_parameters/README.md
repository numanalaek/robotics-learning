# 09 — Default Parameters

Giving default values to function parameters so they can be called with varying numbers of arguments.

## Four Important Things about Default Parameters

| # | Concept | Example |
|---|--------|--------|
| 1 | Parameters can have **default values** | `void func(int x = 10);` |
| 2 | Arguments are filled **left to right** | Cannot skip `func(, 20)` ❌ |
| 3 | Defaults only on the **rightmost parameters** | `void func(int a, int b = 5);` ✅ |
| 4 | Reduces the need for **overloading** | 1 function with defaults = 4 ways to call |

## Code — `default_parameters.cpp`

```cpp
#include <iomanip>
#include <iostream>

void robotStatus(
    int battery = 100,
    double voltage = 24.0,
    bool obstacle = false)
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout
        << "Battery  : " << battery << "%\n"
        << "Voltage  : " << voltage << " V\n"
        << "Obstacle : " << (obstacle ? "YES" : "NO")
        << "\n\n";
}

int main()
{
    robotStatus();
    robotStatus(80);
    robotStatus(80, 23.5);
    robotStatus(80, 23.5, true);
    return 0;
}
```

## Output

```
Battery  : 100%
Voltage  : 24.0 V
Obstacle : NO

Battery  : 80%
Voltage  : 24.0 V
Obstacle : NO

Battery  : 80%
Voltage  : 23.5 V
Obstacle : NO

Battery  : 80%
Voltage  : 23.5 V
Obstacle : YES
```

## How It Works

```
Call                            battery    voltage    obstacle
─────────────────────────────────────────────────────────────
robotStatus()                      100       24.0       false
robotStatus(80)                     80       24.0       false
robotStatus(80, 23.5)               80       23.5       false
robotStatus(80, 23.5, true)         80       23.5       true
```

Parameters that are not given an argument will use their default values.

## Default Parameter Rules

✅ **Allowed:**
```cpp
void func(int a, int b = 10);         // right parameter default
void func(int a = 1, int b = 2);      // all default
void func(int a, int b = 5, int c = 0); // some default
```

❌ **Not allowed:**
```cpp
void func(int a = 10, int b);         // left default, right not
void func(int a = 1, int b = 2, int c); // skip middle
```

## Command Line

```bash
g++ default_parameters.cpp -o default_parameters && ./default_parameters
g++ default_parameters_test1.cpp -o default_parameters_test1 && ./default_parameters_test1
g++ default_parameters_test2.cpp -o default_parameters_test2 && ./default_parameters_test2
```

## Analogy

Default parameters are like **preset modes on a robot**.

| Call | Mode |
|-----------|------|
| `robotStatus()` | "Auto" — all use defaults |
| `robotStatus(80)` | "Custom battery" — battery set, rest default |
| `robotStatus(80, 23.5)` | "Custom power" — battery & voltage set |
| `robotStatus(80, 23.5, true)` | "Manual" — all set by user |

## Exercises

1. Change the default of `obstacle` to `true`. Call `robotStatus()` — what is the output?
2. Add parameter `int temperature = 25` at the rightmost position.
3. Call `robotStatus(80, true)` — does it cause a compilation error? Why?
4. Create a function `moveRobot(int steps = 1, double speed = 1.0)` — call it in 3 different ways.
