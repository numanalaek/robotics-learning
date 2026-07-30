# 16. Encapsulation & Struct Composition

Class data members are made **private** so they cannot be accessed directly from outside the class. Access is only through **public member functions**. Data is also grouped into **structs** to be more structured and closer to real robot representation.

## Compile & Run

```bash
# Program 1 — Encapsulation dasar
g++ encapsulation.cpp -o encapsulation && ./encapsulation

# Program 2 — Struct composition + constructor parameterized
g++ encapsulation_test.cpp -o encapsulation_test && ./encapsulation_test
```

## Program 1 — `encapsulation.cpp`

Basic encapsulation: `battery` is `private`, access only through `printStatus()`.

```cpp
Robot robot;
// robot.battery = 50;  // ERROR: private!
robot.printStatus();     // OK: public member function
```

## Program 2 — `encapsulation_test.cpp`

Data is grouped into structs and classes using **trailing underscore** (`_`):

```cpp
struct Battery {
    int percent;
    double voltage;
};

struct Velocity {
    double linear;
    double angular;
};

class Robot {
private:
    Battery battery_;
    Velocity velocity_;
    bool emergency_;
    // ...
};
```

Constructor receives `const&` to struct, not individual parameters:

```cpp
Robot(const Battery& battery, const Velocity& velocity, bool emergency)
    : battery_(battery),
      velocity_(velocity),
      emergency_(emergency)
{
}
```

Object creation in `main()`:

```cpp
Robot robot1({100, 24.5}, {0.0, 0.0}, false);
Robot robot2({85, 48.0}, {1.5, 0.0}, false);
```

## Why is this important in ROS 2?

- **Encapsulation** — prevents sensor/motor data from being arbitrarily changed from outside the class.
- **Struct composition** — robot data (Battery, Velocity, Pose) is more modular and reusable.
- **Trailing underscore** (`_`) — naming convention widely used in ROS 2 codebases, distinguishing members from constructor parameters.
