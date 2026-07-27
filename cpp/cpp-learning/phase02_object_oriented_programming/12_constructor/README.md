# Constructor dalam C++

## Empat Hal Penting tentang Constructor

| # | Aturan | Contoh |
|---|--------|--------|
| 1 | Dipanggil **otomatis** saat objek dibuat | `Robot robot;` → `Robot()` langsung jalan |
| 2 | Nama **sama persis** dengan nama class | `class Robot { Robot() { } }` |
| 3 | **Tidak punya return type** (bukan `void`) | `Robot();` ✅ | `void Robot();` ❌ |
| 4 | **Menginisialisasi** data member agar objek langsung valid | `: battery(100), voltage(24.5)` |

## Kode

```cpp
#include <iostream>
#include <string>

struct Pose
{
    double x;
    double y;
};

class Robot
{
private:
    int battery;
    double voltage;
    std::string mode;
    Pose pose;

public:
    Robot()
        : battery(100),
          voltage(24.5),
          mode("READY"),
          pose{0.0, 0.0}
    {
    }

    void printStatus() const
    {
        std::cout
            << "Robot Status:\n"
            << "Battery : " << battery << "%\n"
            << "Voltage : " << voltage << " V\n"
            << "Mode    : " << mode << "\n"
            << "Pose    : (" << pose.x << ", "
            << pose.y << ")\n";
    }
};

int main()
{
    Robot robot;

    robot.printStatus();

    return 0;
}
```

## Command Line

```bash
# Kompilasi
g++ -std=c++11 -o constructor constructor.cpp

# Jalankan
./constructor

# Kompilasi + jalankan sekali
g++ -std=c++11 -o constructor constructor.cpp && ./constructor
```

## Analogi

Constructor seperti **surat lahir** — saat objek "lahir", semua data dasarnya sudah terisi.

| Objek | Lahir dengan nilai default |
|-------|---------------------------|
| `Robot` | battery=100, voltage=24.5, mode="READY", pose=(0,0) |
| `std::string` | `""` (string kosong) |
| `std::vector` | kosong (`size() == 0`) |

Tanpa constructor → objek lahir dengan data **tidak terdefinisi** (sampah).

## Latihan

1. Hapus constructor → compile → lihat error: `no appropriate default constructor available`
2. Ganti `Robot()` menjadi `void Robot()` → lihat error: `return type specification for constructor invalid`
3. Tambahkan parameter: `Robot(int level) : battery(level)` → panggil `Robot robot(50);`
4. Gunakan member initializer list vs assignment — apa bedanya?
