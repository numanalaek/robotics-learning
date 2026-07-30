# 17. Getter & Setter

Getters and setters are public member functions that control access to private data members. Getters take a snapshot of data, setters validate data before storing it.

## Compile & Run

```bash
g++ getter.cpp -o getter && ./getter
g++ setter.cpp -o setter && ./setter
```

## `getter.cpp` — Read-Only Access

`Battery` and `Velocity` struct data are returned **by value** because they are small (int + double).

```cpp
Battery getBattery() const { return battery_; }
Velocity getVelocity() const { return velocity_; }
```

The caller stores the result with `const auto` to clarify that this is a snapshot that will not be modified:

```cpp
const auto battery = robot.getBattery();
const auto velocity = robot.getVelocity();
```

## `setter.cpp` — Validated Write Access

Setter receives a complete struct (`const Type&`), not split parameters. Validation is done before assignment.

```cpp
void setBattery(const Battery& battery) {
    if (battery.percent < 0 || battery.percent > 100)
        throw std::out_of_range{"Battery percent must be 0–100"};
    if (battery.voltage <= 0.0)
        throw std::out_of_range{"Voltage must be > 0"};
    battery_ = battery;
}
```

Call with braced-init-list or existing object:

```cpp
robot.setBattery({85, 23.8});       // braced-init-list
Battery b{85, 23.8};
robot.setBattery(b);                // object
```

Validation applied:

| Field | Rentang |
|-------|---------|
| Battery percent | 0 – 100 |
| Voltage | > 0 |
| Linear velocity | >= 0 |
| Angular velocity | -10.0 – 10.0 rad/s |

## Practical Return Type Rules

| Ukuran objek | Return type | Contoh |
|-------------|-------------|--------|
| **Kecil** (int, double, struct 1–2 field) | `T` (by value) | `Battery`, `Velocity`, `Pose2D` |
| **Besar** (vector, string, image, cloud) | `const T&` (by reference) | `std::vector<double>`, `sensor_msgs::msg::LaserScan` |

## Why This Design Matters in ROS 2?

- **Setter receives struct, not individual parameters** — if the data structure gains fields, the setter signature does not change. Callers do not need to be updated one by one.
- **Getter returns by value for small types** — safe from dangling references and as efficient as references.
- **Setter validates data** — prevents invalid robot state (battery > 100%, negative velocity, etc.).
