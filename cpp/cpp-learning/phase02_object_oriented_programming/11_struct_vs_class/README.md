# 11 — Struct, Class & Object

Understanding the difference between struct and class, and the concept of blueprint and object in C++.

## Program

### `robot_struct.cpp`
Struct `Robot` with 4 data members. Two objects (`robot1`, `robot2`) with different data.

### `robot_class.cpp`
Class `Robot` identical to struct, but needs explicit `public:`.

### `struct_test.cpp`
Basic struct exercise with 3 members and one object.

### `class_vs_struct.cpp`
Direct side-by-side comparison of struct vs class in one program.

### `class_test.cpp`
Class exercise with 2 objects demonstrating that each object has its own data.

## Concepts

- **Struct / Class** — blueprint or data type that defines the Robot's shape
- **Object** — real instance created from the blueprint (`Robot robot1;`)
- **Data member** — variable belonging to an object, accessed with dot (`robot1.battery`)
- **Default access** — struct = `public`, class = `private`
- Each object has **its own copy of data** — changing one object does not affect another

## When to Use Struct vs Class (Rule of Thumb)

**Use `struct` for pure data (Plain Old Data / POD):**
- Only carries data, has no behavior (function/method)
- Robotics examples: `Pose`, `BatteryState`, `LidarScan`, `WheelEncoder`, `MotorCommand`, `RobotConfig`
- ROS 2 examples: `Header`, `Pose`, `Twist`, `Vector3`, `Point`, `Quaternion`, `ColorRGBA`

```cpp
struct Pose
{
    double x;
    double y;
    double theta;
};
```

**Use `class` for components that "do something" (have state, rules, behavior):**
- Has member functions, manages internal state, validates input
- Robotics examples: `Robot`, `MotorController`, `Navigation`, `Localization`, `LidarDriver`, `BatteryMonitor`, `RobotNode`

```cpp
class MotorController
{
public:
    void setSpeed(double rpm);
    void stop();

private:
    double rpm_;
};
```

### Patterns in ROS 2

| struct (Data) | class (Behavior) |
|---------------|------------------|
| Header | Node |
| Pose / Twist / Vector3 | Publisher / Subscription |
| Point / Quaternion | Executor / ActionServer |
| ColorRGBA / BatteryState | LifecycleNode / Timer |
| LaserScan / WheelEncoder | MotorController / Navigation |

### Summary for Robotics Engineer

| Category | Use | Examples |
|----------|-----|---------|
| Data only (POD) | `struct` | `Pose`, `BatteryState`, `LidarScan` |
| Has functions, state, logic | `class` | `Robot`, `MotorController`, `RobotNode` |

This convention aligns with modern C++ projects and eases the transition to ROS 2.
