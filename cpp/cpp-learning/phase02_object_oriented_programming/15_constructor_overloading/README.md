# 15. Constructor Overloading

One class can have multiple constructors with different parameters. The compiler selects the constructor that matches the arguments when the object is created.

## Compile & Run

```bash
# Program 1
g++ constructor_overloading.cpp -o constructor_overloading && ./constructor_overloading

# Program 2
g++ constructor_overloading2.cpp -o constructor_overloading2 && ./constructor_overloading2
```

## Program 1 — `constructor_overloading.cpp`

```cpp
// 4 constructors with different parameters
Robot();                          // default: battery=100, voltage=24.5, mode=READY
Robot(int battery_);              // battery set, rest default
Robot(int battery_, double voltage_);         // battery & voltage set
Robot(int battery_, double voltage_, const std::string& mode_);  // all set
```

Compiler selects based on arguments:
- `Robot r1;` → `Robot()`
- `Robot r2(80);` → `Robot(int)`
- `Robot r3(75, 24.1);` → `Robot(int, double)`
- `Robot r4(60, 23.8, "AUTO");` → `Robot(int, double, string)`

## Program 2 — `constructor_overloading2.cpp`

```cpp
struct Pose { double x; double y; };

// 3 constructors
Robot();                          // battery=100, pose={0,0}
Robot(int battery_);              // battery set, pose={0,0}
Robot(int battery_, Pose pose_);  // battery & pose set
```

## Why is this important in ROS 2?

A single sensor driver class can have many constructors for different levels of configuration:

```cpp
LaserScanner scanner;
LaserScanner scanner("/dev/ttyUSB0");
LaserScanner scanner("/dev/ttyUSB0", 115200);
LaserScanner scanner("/dev/ttyUSB0", 115200, true);
```
