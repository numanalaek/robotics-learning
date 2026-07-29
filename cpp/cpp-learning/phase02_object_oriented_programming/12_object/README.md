# 12. Object dalam C++

## Empat Hal Penting tentang Object

| # | Aturan | Contoh |
| --- | -------- | -------- |
| 1 | Object adalah **instance nyata** dari class (blueprint) | `Robot robot1;` |
| 2 | Setiap object punya **memori sendiri** | `robot1.battery` ≠ `robot2.battery` |
| 3 | Perubahan satu object **tidak memengaruhi** object lain | `robot1.battery = 0` → `robot2` tetap 40 |
| 4 | Alamat setiap object **berbeda** di memory | `&robot1` ≠ `&robot2` |

## Kode

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

## Output

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

## Diagram Memori

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

## Command Line

```bash
# Kompilasi
g++ -std=c++11 -o object object.cpp

# Jalankan
./object

# Kompilasi + jalankan sekali
g++ -std=c++11 -o object object.cpp && ./object
```

## Analogi

Class = **cetakan kue** → Object = **kue hasil cetakan**.

| Konsep | Analogi |
| -------- | --------- |
| `class Robot { }` | Cetakan kue robot |
| `Robot robot1;` | Kue robot pertama |
| `Robot robot2;` | Kue robot kedua |
| `robot1.battery = 90` | Taburan coklat di kue 1 |
| `robot2.battery = 40` | Taburan coklat di kue 2 |

Setiap kue punya topping sendiri — mengganti topping kue 1 tidak mengubah kue 2.

## Latihan

1. Tambah `Robot robot3;` — beri nilai berbeda. Prediksi alamatnya.
2. Cetak `sizeof(Robot)` — berapa byte setiap object?
3. Buat array `Robot robot[3];` — apakah alamatnya berurutan?
4. Bandingkan alamat `&robot1.voltage` dengan `&robot1.battery` — berapa bedanya? (petunjuk: `int` = 4 byte)
