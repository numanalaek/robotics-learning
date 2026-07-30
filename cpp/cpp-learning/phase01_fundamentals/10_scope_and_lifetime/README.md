# 10 — Scope & Lifetime

Understanding variable scope and lifetime in C++.

## Four Important Things about Scope & Lifetime

| # | Concept | Example |
|---|--------|--------|
| 1 | **Global scope** — variable outside functions, lives for the whole program | `int robot_id = 1;` |
| 2 | **Local scope** — variable inside a function, lives while function is called | `int battery = 100;` in `main()` |
| 3 | **Block scope** — variable inside `{ }`, lives only within the block | `int sensor = 45;` in `{ }` |
| 4 | **LIFO** — last created object is destroyed first | Destructor in reverse order of constructor |

## Program 1 — `scope.cpp`

```cpp
#include <iostream>

int robot_id = 1;           // global scope

int main()
{
    int battery = 100;       // local scope (main)

    std::cout << "Robot ID : " << robot_id << '\n';
    std::cout << "Battery  : " << battery << '\n';

    {
        int sensor_distance = 45;  // block scope
        std::cout << "Sensor   : " << sensor_distance << " cm\n";
    }

    // std::cout << sensor_distance << '\n';  // ERROR: di luar block
    return 0;
}
```

### Output

```
Robot ID : 1
Battery  : 100
Sensor   : 45 cm
```

## Program 2 — `lifetime.cpp`

```cpp
#include <iostream>

struct Robot
{
    int id;
    const char* name;

    Robot(int robot_id, const char* n) : id(robot_id), name(n)
    {
        std::cout << name << " created\n";
    }

    ~Robot()
    {
        std::cout << name << " destroyed\n";
    }
};

Robot robot_id{1, "Robot ID"};

void robotFunction()
{
    Robot battery{100, "Battery"};
    std::cout << "Battery: " << battery.id << '\n';

    {
        Robot sensor_distance{45, "Sensor"};
        std::cout << "Sensor: " << sensor_distance.id << " cm\n";
    }
}

int main()
{
    std::cout << '\n';
    robotFunction();
    std::cout << '\n';
    return 0;
}
```

### Output

```
Robot ID created       ← global, dibuat sebelum main

Battery created        ← local di robotFunction()
Battery: 100
Sensor created          ← block scope di dalam robotFunction()
Sensor: 45 cm
Sensor destroyed        ← keluar block scope
Battery destroyed       ← keluar robotFunction()

Robot ID destroyed     ← global, dihancurkan setelah main
```

## Scope Rules

```
┌─────────────────────────────────────┐
│ Global scope                        │
│  int robot_id = 1;                  │
│                                     │
│  ┌──────────────────────────────┐   │
│  │ main() local scope           │   │
│  │  int battery = 100;          │   │
│  │                              │   │
│  │  ┌────────────────────┐      │   │
│  │  │ block scope        │      │   │
│  │  │ int sensor = 45;   │      │   │
│  │  └────────────────────┘      │   │
│  │                              │   │
│  └──────────────────────────────┘   │
└─────────────────────────────────────┘
```

Inner scope can access outer scope. Outer scope **cannot** access inner scope.

## Command Line

```bash
g++ scope.cpp -o scope && ./scope
g++ lifetime.cpp -o lifetime && ./lifetime
g++ scope_and_lifetime_test1.cpp -o scope_and_lifetime_test1 && ./scope_and_lifetime_test1
g++ scope_and_lifetime_test2.cpp -o scope_and_lifetime_test2 && ./scope_and_lifetime_test2
g++ lifetime_test1.cpp -o lifetime_test1 && ./lifetime_test1
```

## Analogy

Scope is like a **work area in a robot workshop**.

| Scope | Analogy |
|-------|---------|
| Global | Central warehouse — all technicians can access |
| Local (function) | Technician's workbench — only that technician has access |
| Block (`{ }`) | Desk drawer — only open while the desk is in use |

## Exercises

1. In `scope.cpp`, uncomment `std::cout << sensor_distance` — compile and see the error.
2. In `lifetime.cpp`, notice the order of "destroyed" — why is it reversed from "created"?
3. Add `Robot status{"Status", 1};` in global scope — when is it destroyed?
4. Create a block `{ }` inside `main()` containing `Robot local{"Local", 2};`. Predict the output.
