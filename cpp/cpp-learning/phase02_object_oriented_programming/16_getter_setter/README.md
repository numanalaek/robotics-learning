# 16. Getter & Setter

Getter dan setter adalah public member function yang mengontrol akses ke data member private. Getter mengambil snapshot data, setter memvalidasi data sebelum menyimpannya.

## Compile & Run

```bash
g++ getter.cpp -o getter && ./getter
g++ setter.cpp -o setter && ./setter
```

## `getter.cpp` — Read-Only Access

Data struct `Battery` dan `Velocity` dikembalikan **by value** karena ukurannya kecil (int + double).

```cpp
Battery getBattery() const { return battery_; }
Velocity getVelocity() const { return velocity_; }
```

Caller menyimpan hasilnya dengan `const auto` untuk memperjelas bahwa ini adalah snapshot yang tidak akan diubah:

```cpp
const auto battery = robot.getBattery();
const auto velocity = robot.getVelocity();
```

## `setter.cpp` — Validated Write Access

Setter menerima struct lengkap (`const Type&`), bukan parameter terpecah. Validasi dilakukan sebelum assignment.

```cpp
void setBattery(const Battery& battery) {
    if (battery.percent < 0 || battery.percent > 100)
        throw std::out_of_range{"Battery percent must be 0–100"};
    if (battery.voltage <= 0.0)
        throw std::out_of_range{"Voltage must be > 0"};
    battery_ = battery;
}
```

Pemanggilan dengan braced-init-list atau object eksisting:

```cpp
robot.setBattery({85, 23.8});       // braced-init-list
Battery b{85, 23.8};
robot.setBattery(b);                // object
```

Validasi yang diterapkan:

| Field | Rentang |
|-------|---------|
| Battery percent | 0 – 100 |
| Voltage | > 0 |
| Linear velocity | >= 0 |
| Angular velocity | -10.0 – 10.0 rad/s |

## Aturan Praktis Return Type

| Ukuran objek | Return type | Contoh |
|-------------|-------------|--------|
| **Kecil** (int, double, struct 1–2 field) | `T` (by value) | `Battery`, `Velocity`, `Pose2D` |
| **Besar** (vector, string, image, cloud) | `const T&` (by reference) | `std::vector<double>`, `sensor_msgs::msg::LaserScan` |

## Mengapa Desain Ini Penting di ROS 2?

- **Setter menerima struct, bukan parameter individu** — jika struktur data bertambah field, signature setter tidak berubah. Caller tidak perlu diperbaiki satu per satu.
- **Getter return by value untuk tipe kecil** — aman dari dangling reference dan sama efisiennya dengan reference.
- **Setter memvalidasi data** — mencegah state robot tidak valid (battery > 100%, kecepatan negatif, dll).
