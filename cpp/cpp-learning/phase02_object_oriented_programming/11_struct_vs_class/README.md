# 11 — Struct, Class & Object

Memahami perbedaan struct dan class, serta konsep blueprint dan object dalam C++.

## Program

### `robot_struct.cpp`
Struct `Robot` dengan 4 data member. Dua object (`robot1`, `robot2`) dengan data berbeda.

### `robot_class.cpp`
Class `Robot` yang identik dengan struct, tetapi perlu `public:` eksplisit.

### `struct_test.cpp`
Latihan dasar struct dengan 3 member dan satu object.

### `class_vs_struct.cpp`
Perbandingan langsung struct vs class secara berdampingan dalam satu program.

### `class_test.cpp`
Latihan class dengan 2 object dan demonstrasi bahwa tiap object punya data sendiri.

## Konsep

- **Struct / Class** — blueprint atau tipe data yang mendefinisikan bentuk Robot
- **Object** — instance nyata yang dibuat berdasarkan blueprint (`Robot robot1;`)
- **Data member** — variabel milik object, diakses dengan titik (`robot1.battery`)
- **Default access** — struct = `public`, class = `private`
- Setiap object punya **salinan data sendiri** — mengubah object lain tidak memengaruhinya

## Kapan Pakai Struct vs Class (Rule of Thumb)

**Gunakan `struct` untuk data murni (Plain Old Data / POD):**
- Hanya membawa data, tidak punya perilaku (function/method)
- Contoh robotik: `Pose`, `BatteryState`, `LidarScan`, `WheelEncoder`, `MotorCommand`, `RobotConfig`
- Contoh ROS 2: `Header`, `Pose`, `Twist`, `Vector3`, `Point`, `Quaternion`, `ColorRGBA`

```cpp
struct Pose
{
    double x;
    double y;
    double theta;
};
```

**Gunakan `class` untuk komponen yang "melakukan sesuatu" (punya state, aturan, perilaku):**
- Punya member function, mengelola state internal, memvalidasi input
- Contoh robotik: `Robot`, `MotorController`, `Navigation`, `Localization`, `LidarDriver`, `BatteryMonitor`, `RobotNode`

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

### Pattern di ROS 2

| struct (Data) | class (Perilaku) |
|---------------|------------------|
| Header | Node |
| Pose / Twist / Vector3 | Publisher / Subscription |
| Point / Quaternion | Executor / ActionServer |
| ColorRGBA / BatteryState | LifecycleNode / Timer |
| LaserScan / WheelEncoder | MotorController / Navigation |

### Ringkasan untuk Robotics Engineer

| Kategori | Gunakan | Contoh |
|----------|---------|--------|
| Hanya data (POD) | `struct` | `Pose`, `BatteryState`, `LidarScan` |
| Punya fungsi, state, logika | `class` | `Robot`, `MotorController`, `RobotNode` |

Kebiasaan ini selaras dengan proyek C++ modern dan mempermudah transisi ke ROS 2.
