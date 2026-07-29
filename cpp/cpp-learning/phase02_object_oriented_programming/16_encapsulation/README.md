# 16. Encapsulation & Struct Composition

Data member class dibuat **private** agar tidak bisa diakses langsung dari luar class. Akses hanya melalui **public member function**. Data juga dikelompokkan dalam **struct** agar lebih terstruktur dan mendekati representasi robot nyata.

## Compile & Run

```bash
# Program 1 — Encapsulation dasar
g++ encapsulation.cpp -o encapsulation && ./encapsulation

# Program 2 — Struct composition + constructor parameterized
g++ encapsulation_test.cpp -o encapsulation_test && ./encapsulation_test
```

## Program 1 — `encapsulation.cpp`

Encapsulation dasar: `battery` bersifat `private`, akses hanya melalui `printStatus()`.

```cpp
Robot robot;
// robot.battery = 50;  // ERROR: private!
robot.printStatus();     // OK: public member function
```

## Program 2 — `encapsulation_test.cpp`

Data dikelompokkan dalam struct dan class menggunakan **trailing underscore** (`_`):

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

Constructor menerima `const&` ke struct, bukan parameter individual:

```cpp
Robot(const Battery& battery, const Velocity& velocity, bool emergency)
    : battery_(battery),
      velocity_(velocity),
      emergency_(emergency)
{
}
```

Pembuatan object di `main()`:

```cpp
Robot robot1({100, 24.5}, {0.0, 0.0}, false);
Robot robot2({85, 48.0}, {1.5, 0.0}, false);
```

## Mengapa penting di ROS 2?

- **Encapsulation** — mencegah data sensor/motor diubah sembarangan dari luar class.
- **Struct composition** — data robot (Battery, Velocity, Pose) lebih modular dan bisa dipakai ulang.
- **Trailing underscore** (`_`) — gaya penamaan yang banyak digunakan di codebase ROS 2, membedakan member dengan parameter constructor.
