# 12. Object dalam C++

## Four Important Things About Object

| # | Rule | Example |
|---|------|--------|
| 1 | Object is a **real instance** of a class (blueprint) | `Robot robot1;` |
| 2 | Each object has **its own memory** | `robot1.battery` ≠ `robot2.battery` |
| 3 | Changing one object **does not affect** another object | `robot1.battery = 0` → `robot2` stays 40 |
| 4 | Each object has a **different address** in memory | `&robot1` ≠ `&robot2` |

## Program 1 — Two Independent Objects (`object.cpp`)

### Code

```cpp
#include <iostream>

class Robot
{
public:
    int battery;
    double voltage;
    double velocity;
};

int main()
{
    Robot robot1;
    Robot robot2;

    robot1.battery = 90;
    robot1.voltage = 24.5;
    robot1.velocity = 0.5;

    robot2.battery = 40;
    robot2.voltage = 12.0;
    robot2.velocity = 1.2;

    std::cout
        << "robot1\n"
        << "  &robot1         = " << &robot1 << '\n'
        << "  &robot1.battery = " << &robot1.battery << '\n'
        << "  Battery         = " << robot1.battery << "%\n"
        << "  Voltage         = " << robot1.voltage << " V\n"
        << "  Velocity        = " << robot1.velocity << " m/s\n"
        << "\n"
        << "robot2\n"
        << "  &robot2         = " << &robot2 << '\n'
        << "  &robot2.battery = " << &robot2.battery << '\n'
        << "  Battery         = " << robot2.battery << "%\n"
        << "  Voltage         = " << robot2.voltage << " V\n"
        << "  Velocity        = " << robot2.velocity << " m/s\n";

    robot1.battery = 0;

    std::cout
        << "\nSetelah robot1.battery = 0:\n"
        << "  robot1.battery = " << robot1.battery << "%\n"
        << "  robot2.battery = " << robot2.battery << "%\n"
        << "  (robot2 tidak terpengaruh)\n";
}
```

### Output

```
robot1
  &robot1         = 0x7ffc7ed84cf0
  &robot1.battery = 0x7ffc7ed84cf0
  Battery         = 90%
  Voltage         = 24.5 V
  Velocity        = 0.5 m/s

robot2
  &robot2         = 0x7ffc7ed84d10
  &robot2.battery = 0x7ffc7ed84d10
  Battery         = 40%
  Voltage         = 12 V
  Velocity        = 1.2 m/s

Setelah robot1.battery = 0:
  robot1.battery = 0%
  robot2.battery = 40%
  (robot2 tidak terpengaruh)
```

### Memory Diagram

```
   Robot class (blueprint)
         │
    ┌────┴────┐
    ▼         ▼
 robot1     robot2
 ┌───────┐  ┌───────┐
 │battery│  │battery│
 │= 90   │  │= 40   │
 ├───────┤  ├───────┤
 │voltage│  │voltage│
 │= 24.5 │  │= 12.0 │
 ├───────┤  ├───────┤
 │veloc. │  │veloc. │
 │= 0.5  │  │= 1.2  │
 └───────┘  └───────┘
 &robot1    &robot2
 (berbeda)  (berbeda)
```

---

## Program 2 — Copy Object (`object_copy.cpp`)

Proves that `Robot robot2 = robot1;` creates a **copy**, not a reference.

### Code

```cpp
#include <iostream>

class Robot
{
public:
    int battery;
    double voltage;
    double velocity;
};

int main()
{
    Robot robot1;
    robot1.battery = 90;
    robot1.voltage = 24.5;
    robot1.velocity = 0.5;

    // Copy Initialization
    // Semua member (battery, voltage, velocity)
    // disalin (copied) dari robot1 ke robot2.
    //
    // Yang sebenarnya terjadi:
    //   robot2.battery  = robot1.battery;   // 90
    //   robot2.voltage  = robot1.voltage;   // 24.5
    //   robot2.velocity = robot1.velocity;  // 0.5
    Robot robot2 = robot1;

    // Ubah robot2 — robot1 tidak terpengaruh
    robot2.battery = 50;
    robot2.voltage = 12.0;
    robot2.velocity = 1.2;

    std::cout
        << "Robot1\n"
        << "  &robot1         = " << &robot1 << '\n'
        << "  &robot1.battery = " << &robot1.battery << '\n'
        << "  Battery         = " << robot1.battery << '\n'
        << "  Voltage         = " << robot1.voltage << '\n'
        << "  Velocity        = " << robot1.velocity << "\n\n";

    std::cout
        << "Robot2\n"
        << "  &robot2         = " << &robot2 << '\n'
        << "  &robot2.battery = " << &robot2.battery << '\n'
        << "  Battery         = " << robot2.battery << '\n'
        << "  Voltage         = " << robot2.voltage << '\n'
        << "  Velocity        = " << robot2.velocity << '\n';

    std::cout
        << "\n&robot1 = " << &robot1 << '\n'
        << "&robot2 = " << &robot2 << '\n'
        << "(alamat berbeda -> object berbeda, bukan reference)\n";
}
```

### Output

```
Robot1
  &robot1         = 0x7ffc3594bff0
  &robot1.battery = 0x7ffc3594bff0
  Battery         = 90
  Voltage         = 24.5
  Velocity        = 0.5

Robot2
  &robot2         = 0x7ffc3594c010
  &robot2.battery = 0x7ffc3594c010
  Battery         = 50
  Voltage         = 12
  Velocity        = 1.2

&robot1 = 0x7ffc3594bff0
&robot2 = 0x7ffc3594c010
(alamat berbeda -> object berbeda, bukan reference)
```

### Copy Visualization

```
Blueprint
  Robot
   │
   │
   ├──────────────────┐
   ▼                  ▼
robot1            robot2 (copy dari robot1)
┌──────────┐     ┌──────────┐
│ battery  │     │ battery  │
│ = 90     │     │ = 90     │  ← nilai awal sama
├──────────┤     ├──────────┤
│ voltage  │     │ voltage  │
│ = 24.5   │     │ = 24.5   │
├──────────┤     ├──────────┤
│ velocity │     │ velocity │
│ = 0.5    │     │ = 0.5    │
└──────────┘     └──────────┘

Setelah robot2.battery = 50:

robot1            robot2
┌──────────┐     ┌──────────┐
│ battery  │     │ battery  │
│ = 90     │     │ = 50     │  ← berbeda!
├──────────┤     ├──────────┤
│ voltage  │     │ voltage  │
│ = 24.5   │     │ = 12.0   │
├──────────┤     ├──────────┤
│ velocity │     │ velocity │
│ = 0.5    │     │ = 1.2    │
└──────────┘     └──────────┘
&robot1          &robot2
(berbeda)        (berbeda)
```

### COPY vs REFERENCE

```cpp
Robot robot2 = robot1;   // ← COPY
Robot &robot2 = robot1;  // ← REFERENCE
```

**COPY Visualization:**

```
robot1 ──────────► object A
robot2 ──────────► object B (salinan dari A)
```

`robot2` is a **new object** at a different address. Changing `robot2` does not affect `robot1`.

**REFERENCE Visualization:**

```
robot1 ──────────► object A
                      ▲
                      │
robot2 ───────────────┘
```

`robot2` is just **another name (alias)** for `robot1`. Their address is THE SAME. Changing `robot2` = changing `robot1`.

### Connection to Copy Constructor

Without realizing it, you have already touched a major concept in C++:

```cpp
Robot robot2 = robot1;
```

When this line is written, the compiler uses the **default copy constructor** (implicit copy constructor). Even though you have never written:

```cpp
Robot(const Robot &other);
```

the compiler creates it automatically — copying each member one by one from `robot1` to `robot2`.

### Ideal Learning Flow

```
Class
   ↓
Object
   ↓
Constructor
   ↓
Parameterized Constructor
   ↓
Object Copy        ← (Anda di sini)
   ↓
Copy Constructor
   ↓
Destructor
   ↓
Assignment Operator
```

This is the order used in good Modern C++ books. With this foundation, when you later get into **smart pointers, RAII, and rclcpp (ROS 2)**, you will understand not just how to write code, but also what happens in memory every time an object is created, copied, or destroyed.

## Command Line

```bash
# Program 1 — object.cpp
g++ object.cpp -o object && ./object

# Program 2 — object_copy.cpp
g++ object_copy.cpp -o object_copy && ./object_copy
```

## Analogy

| Concept | Analogy |
|---------|---------|
| `class Robot { }` | Robot cookie cutter |
| `Robot robot1;` | First robot cookie |
| `Robot robot2;` | Second robot cookie |
| `robot1.battery = 90` | Chocolate sprinkles on cookie 1 |
| `robot2.battery = 40` | Chocolate sprinkles on cookie 2 |

Each cookie has its own topping — changing cookie 1's topping does not change cookie 2.

| Copy Concept | Analogy |
|-------------|---------|
| `Robot robot2 = robot1;` (copy) | Photocopy of a recipe — the copy has its own book |
| `Robot &ref = robot1;` (reference) | Borrowing the original recipe book — scribbles damage the original |

## Exercises

1. Add `Robot robot3;` — give it different values. Predict its address.
2. Print `sizeof(Robot)` — how many bytes per object?
3. Create an array `Robot robot[3];` — are the addresses sequential?
4. Compare addresses `&robot1.voltage` with `&robot1.battery` — what is the difference? (hint: `int` = 4 bytes)
5. In `object_copy.cpp`, replace `Robot robot2 = robot1;` with `Robot &robot2 = robot1;` — what happens to the output?
6. Predict the output before running: `robot1.battery = 90; Robot robot2 = robot1; robot1.battery = 0;` — what is `robot2.battery`?
