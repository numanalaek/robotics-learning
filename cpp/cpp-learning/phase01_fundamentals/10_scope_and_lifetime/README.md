# 10 — Scope & Lifetime

Memahami ruang lingkup (scope) dan masa hidup (lifetime) variabel dalam C++ dengan konteks robot.

## Program

### `scope.cpp`
Tiga level scope: global (`robot_id`), local (`battery`), dan block (`sensor_distance`).

### `scope_and_lifetime_test1.cpp`
Perbandingan akses variabel global, function scope, dan main scope.

### `scope_and_lifetime_test2.cpp`
Block scope — variabel di dalam `{}` tidak bisa diakses dari luar.

### `lifetime.cpp`
Urutan pembuatan dan penghancuran objek `Robot` dengan constructor & destructor di berbagai scope.

### `lifetime_test1.cpp`
Masa hidup sederhana — objek dalam block dibuat lalu dihancurkan.

## Konsep

- **Global scope** — variabel di luar fungsi, hidup selama program
- **Local scope** — variabel di dalam fungsi, hidup saat fungsi dipanggil
- **Block scope** — variabel di dalam `{}`, hidup hanya di dalam block
- Scope dalam bisa mengakses variabel scope luar, tapi tidak sebaliknya
- **LIFO** — objek yang dibuat terakhir dihancurkan pertama
- Global dihancurkan paling akhir setelah `main()` selesai
