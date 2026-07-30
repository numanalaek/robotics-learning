# 06 — For Loop

Using `for` loop to read and process sensor data arrays.

## Four Important Things about For Loop

| # | Concept | Example |
|---|--------|--------|
| 1 | `for` repeats code with a **counter** | `for (int i = 0; i < N; ++i)` |
| 2 | Arrays store multiple data with **index 0..n-1** | `sensors[i]` |
| 3 | Accumulate values with `sum += sensors[i]` | `sum += sensors[i];` |
| 4 | Find min/max with **comparison** each iteration | `if (sensors[i] < min) min = sensors[i];` |

## Code — `for_loop.cpp`

```cpp
#include <iostream>

int main()
{
    constexpr int SENSOR_COUNT = 8;
    int sensors[SENSOR_COUNT] =
        {120, 45, 80, 30, 65, 90, 20, 55};

    int sensor_sum = 0;
    int min = sensors[0];
    int max = sensors[0];
    int warning_count = 0;

    for (int i = 0; i < SENSOR_COUNT; ++i)
    {
        std::cout << "Sensor " << i << " = " << sensors[i] << " cm";

        if (sensors[i] < 50)
        {
            std::cout << "  <-- WARNING";
            ++warning_count;
        }
        std::cout << '\n';

        sensor_sum += sensors[i];

        if (sensors[i] < min) min = sensors[i];
        if (sensors[i] > max) max = sensors[i];
    }

    int safe_count = SENSOR_COUNT - warning_count;
    double average = static_cast<double>(sensor_sum) / SENSOR_COUNT;

    std::cout << "\n--- Statistics ---\n";
    std::cout << "Minimum : " << min << " cm\n";
    std::cout << "Maximum : " << max << " cm\n";
    std::cout << "Average : " << average << " cm\n";

    std::cout << "\nWarning : " << warning_count << "\n";
    std::cout << "Safe    : " << safe_count << "\n";

    std::cout << "\nRobot Status : ";
    if (warning_count == 0)
        std::cout << "SAFE\n";
    else if (warning_count <= 2)
        std::cout << "CAUTION\n";
    else
        std::cout << "EMERGENCY\n";

    return 0;
}
```

## Output

```
Sensor 0 = 120 cm
Sensor 1 = 45 cm  <-- WARNING
Sensor 2 = 80 cm
Sensor 3 = 30 cm  <-- WARNING
Sensor 4 = 65 cm
Sensor 5 = 90 cm
Sensor 6 = 20 cm  <-- WARNING
Sensor 7 = 55 cm

--- Statistics ---
Minimum : 20 cm
Maximum : 120 cm
Average : 63.125 cm

Warning : 3
Safe    : 5

Robot Status : EMERGENCY
```

## Flow Eksekusi For Loop

```
for (int i = 0;    i < SENSOR_COUNT;    ++i)
      ①              ②                   ④
      ③
```

| Step | Code | Explanation |
|---------|------|------------|
| ① | `int i = 0` | Initialization (once at start) |
| ② | `i < 8` | Check condition — if true, enter loop |
| ③ | `sensors[i]` | Execute loop body |
| ④ | `++i` | Increment, then return to ② |

## Command Line

```bash
g++ for_loop.cpp -o for_loop && ./for_loop
g++ for_loop_test1.cpp -o for_loop_test1 && ./for_loop_test1
g++ robot_monitor.cpp -o robot_monitor && ./robot_monitor
```

## Analogy

For loop is like a **robot inspection line** — the robot walks along 8 sensors, one by one.

| Loop Part | Analogy |
|-------------|---------|
| `int i = 0` | Start from the first sensor |
| `i < 8` | Check if there are still sensors |
| `sensors[i]` | Read the i-th sensor value |
| `++i` | Move to the next sensor |

## Exercises

1. Change `SENSOR_COUNT` to 16 — what needs to change in the array?
2. Change the warning threshold from 50 to 70 — how does the result change?
3. Add logic: if `warning_count >= 4`, print "EMERGENCY STOP!".
4. Use `for (int i = 7; i >= 0; --i)` — what happens to the output order?
