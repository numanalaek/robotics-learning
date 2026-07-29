# 12. Object dalam C++

## Empat Hal Penting tentang Object

| # | Aturan | Contoh |
|---|--------|--------|
| 1 | Object adalah **instance nyata** dari class (blueprint) | `Robot robot1;` |
| 2 | Setiap object punya **memori sendiri** | `robot1.battery` ≠ `robot2.battery` |
| 3 | Perubahan satu object **tidak memengaruhi** object lain | `robot1.battery = 0` → `robot2` tetap 40 |
| 4 | Alamat setiap object **berbeda** di memory | `&robot1` ≠ `&robot2` |

## Program 1 — Dua Object Berdiri Sendiri (`object.cpp`)

### Kode

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

### Diagram Memori

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

Membuktikan bahwa `Robot robot2 = robot1;` membuat **salinan (copy)**, bukan reference.

### Kode

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

### Visualisasi Copy

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

**Visualisasi COPY:**

```
robot1 ──────────► object A
robot2 ──────────► object B (salinan dari A)
```

`robot2` adalah **object baru** di alamat berbeda. Mengubah `robot2` tidak memengaruhi `robot1`.

**Visualisasi REFERENCE:**

```
robot1 ──────────► object A
                      ▲
                      │
robot2 ───────────────┘
```

`robot2` hanyalah **nama lain (alias)** untuk `robot1`. Alamatnya SAMA. Mengubah `robot2` = mengubah `robot1`.

### Koneksi ke Copy Constructor

Tanpa sadar Anda sudah menyentuh konsep besar dalam C++:

```cpp
Robot robot2 = robot1;
```

Saat baris ini ditulis, compiler menggunakan **copy constructor bawaan** (implicit copy constructor). Walaupun Anda belum pernah menulis:

```cpp
Robot(const Robot &other);
```

compiler membuatkannya secara otomatis — menyalin setiap member satu per satu dari `robot1` ke `robot2`.

### Alur Pembelajaran Ideal

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

Ini adalah urutan yang dipakai di buku-buku Modern C++ yang baik. Dengan fondasi ini, saat nanti masuk ke **smart pointer, RAII, dan rclcpp (ROS 2)**, Anda akan memahami bukan hanya cara menulis kode, tetapi juga apa yang terjadi di memori setiap kali object dibuat, disalin, atau dihancurkan.

## Command Line

```bash
# Program 1 — object.cpp
g++ object.cpp -o object && ./object

# Program 2 — object_copy.cpp
g++ object_copy.cpp -o object_copy && ./object_copy
```

## Analogi

| Konsep | Analogi |
|--------|---------|
| `class Robot { }` | Cetakan kue robot |
| `Robot robot1;` | Kue robot pertama |
| `Robot robot2;` | Kue robot kedua |
| `robot1.battery = 90` | Taburan coklat di kue 1 |
| `robot2.battery = 40` | Taburan coklat di kue 2 |

Setiap kue punya topping sendiri — mengganti topping kue 1 tidak mengubah kue 2.

| Konsep Copy | Analogi |
|-------------|---------|
| `Robot robot2 = robot1;` (copy) | Fotokopi resek — hasil fotokopian punya buku sendiri |
| `Robot &ref = robot1;` (reference) | Pinjam buku resep asli — coretan merusak aslinya |

## Latihan

1. Tambah `Robot robot3;` — beri nilai berbeda. Prediksi alamatnya.
2. Cetak `sizeof(Robot)` — berapa byte setiap object?
3. Buat array `Robot robot[3];` — apakah alamatnya berurutan?
4. Bandingkan alamat `&robot1.voltage` dengan `&robot1.battery` — berapa bedanya? (petunjuk: `int` = 4 byte)
5. Di `object_copy.cpp`, ganti `Robot robot2 = robot1;` dengan `Robot &robot2 = robot1;` — apa yang terjadi pada output?
6. Prediksi output sebelum menjalankan: `robot1.battery = 90; Robot robot2 = robot1; robot1.battery = 0;` — berapa `robot2.battery`?
