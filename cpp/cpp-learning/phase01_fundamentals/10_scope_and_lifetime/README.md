# 10 — Scope & Lifetime

Memahami ruang lingkup (scope) dan masa hidup (lifetime) variabel dalam C++.

## Empat Hal Penting tentang Scope & Lifetime

| # | Konsep | Contoh |
|---|--------|--------|
| 1 | **Global scope** — variabel di luar fungsi, hidup selama program | `int robot_id = 1;` |
| 2 | **Local scope** — variabel di dalam fungsi, hidup saat fungsi dipanggil | `int battery = 100;` di `main()` |
| 3 | **Block scope** — variabel di dalam `{ }`, hidup hanya di dalam blok | `int sensor = 45;` di `{ }` |
| 4 | **LIFO** — objek yang dibuat terakhir dihancurkan pertama | Destructor urutan terbalik dari constructor |

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

## Aturan Scope

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

Scope dalam bisa akses scope luar. Scope luar **tidak bisa** akses scope dalam.

## Command Line

```bash
g++ scope.cpp -o scope && ./scope
g++ lifetime.cpp -o lifetime && ./lifetime
g++ scope_and_lifetime_test1.cpp -o scope_and_lifetime_test1 && ./scope_and_lifetime_test1
g++ scope_and_lifetime_test2.cpp -o scope_and_lifetime_test2 && ./scope_and_lifetime_test2
g++ lifetime_test1.cpp -o lifetime_test1 && ./lifetime_test1
```

## Analogi

Scope seperti **area kerja di bengkel robot**.

| Scope | Analogi |
|-------|---------|
| Global | Gudang pusat — semua teknisi bisa akses |
| Local (fungsi) | Meja kerja teknisi — hanya teknisi itu yang punya akses |
| Block (`{ }`) | Laci meja — hanya saat meja dipakai, lacinya terbuka |

## Latihan

1. Di `scope.cpp`, uncomment `std::cout << sensor_distance` — compile dan lihat error.
2. Di `lifetime.cpp`, perhatikan urutan "destroyed" — mengapa terbalik dari "created"?
3. Tambah `Robot status{"Status", 1};` di global — kapan di-destroy?
4. Buat blok `{ }` di dalam `main()` yang berisi `Robot local{"Local", 2};`. Prediksi output.
