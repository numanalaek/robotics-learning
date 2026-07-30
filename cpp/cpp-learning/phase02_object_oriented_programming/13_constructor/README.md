# 13. Constructor dalam C++

## Four Important Things About Constructor

| # | Rule | Example |
|---|------|--------|
| 1 | Called **automatically** when an object is created | `Robot robot;` → `Robot()` runs immediately |
| 2 | Name is **exactly the same** as the class name | `class Robot { Robot() { } }` |
| 3 | **Has no return type** (not even `void`) | `Robot();` ✅ | `void Robot();` ❌ |
| 4 | **Initializes** data members so the object is immediately valid | `: battery(100), voltage(24.5)` |

## Code

```cpp
#include <iostream>
#include <string>

struct Pose
{
    double x;
    double y;
};

class Robot
{
private:
    int battery;
    double voltage;
    std::string mode;
    Pose pose;

public:
    Robot()
        : battery(100),
          voltage(24.5),
          mode("READY"),
          pose{0.0, 0.0}
    {
    }

    void printStatus() const
    {
        std::cout
            << "Robot Status:\n"
            << "Battery : " << battery << "%\n"
            << "Voltage : " << voltage << " V\n"
            << "Mode    : " << mode << "\n"
            << "Pose    : (" << pose.x << ", "
            << pose.y << ")\n";
    }
};

int main()
{
    Robot robot;

    robot.printStatus();

    return 0;
}
```

## Command Line

```bash
# Kompilasi
g++ -std=c++11 -o constructor constructor.cpp

# Jalankan
./constructor

# Kompilasi + jalankan sekali
g++ -std=c++11 -o constructor constructor.cpp && ./constructor
```

## Analogy

Constructor is like a **birth certificate** — when an object is "born", all its basic data is already filled in.

| Object | Born with default values |
|--------|-------------------------|
| `Robot` | battery=100, voltage=24.5, mode="READY", pose=(0,0) |
| `std::string` | `""` (empty string) |
| `std::vector` | empty (`size() == 0`) |

Without a constructor → the object is born with **undefined** data (garbage).

## Exercises

1. Remove the constructor → compile → see the error: `no appropriate default constructor available`
2. Change `Robot()` to `void Robot()` → see the error: `return type specification for constructor invalid`
3. Add a parameter: `Robot(int level) : battery(level)` → call `Robot robot(50);`
4. Use member initializer list vs assignment — what's the difference?
