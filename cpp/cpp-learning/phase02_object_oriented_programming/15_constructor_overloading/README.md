# 15. Constructor Overloading

Satu class bisa memiliki beberapa constructor dengan parameter berbeda. Compiler memilih constructor yang cocok dengan argumen saat pembuatan object.

## Compile & Run

```bash
# Program 1
g++ constructor_overloading.cpp -o constructor_overloading && ./constructor_overloading

# Program 2
g++ constructor_overloading2.cpp -o constructor_overloading2 && ./constructor_overloading2
```

## Program 1 — `constructor_overloading.cpp`

```cpp
// 4 constructor dengan parameter berbeda
Robot();                          // default: battery=100, voltage=24.5, mode=READY
Robot(int battery_);              // battery diatur, sisanya default
Robot(int battery_, double voltage_);         // battery & voltage diatur
Robot(int battery_, double voltage_, const std::string& mode_);  // semua diatur
```

Compiler memilih berdasarkan argumen:
- `Robot r1;` → `Robot()`
- `Robot r2(80);` → `Robot(int)`
- `Robot r3(75, 24.1);` → `Robot(int, double)`
- `Robot r4(60, 23.8, "AUTO");` → `Robot(int, double, string)`

## Program 2 — `constructor_overloading2.cpp`

```cpp
struct Pose { double x; double y; };

// 3 constructor
Robot();                          // battery=100, pose={0,0}
Robot(int battery_);              // battery diatur, pose={0,0}
Robot(int battery_, Pose pose_);  // battery & pose diatur
```

## Mengapa penting di ROS 2?

Satu class driver sensor bisa memiliki banyak constructor untuk berbagai tingkat konfigurasi:

```cpp
LaserScanner scanner;
LaserScanner scanner("/dev/ttyUSB0");
LaserScanner scanner("/dev/ttyUSB0", 115200);
LaserScanner scanner("/dev/ttyUSB0", 115200, true);
```
