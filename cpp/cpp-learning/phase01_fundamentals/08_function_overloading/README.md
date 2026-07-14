# 08 — Function Overloading

Mendefinisikan beberapa fungsi dengan nama yang sama tetapi parameter berbeda.

## Program

### `function_overloading.cpp`
Tiga versi `printStatus()`:
- `printStatus()` — tanpa parameter, cetak "Robot READY"
- `printStatus(int battery)` — cetak persentase baterai
- `printStatus(int battery, double voltage)` — cetak baterai dan tegangan

### `function_overloading_test1.cpp`
Dua versi `move()`:
- `move()` — maju 1 langkah
- `move(int step)` — maju sejumlah langkah

### `function_overloading_test2.cpp`
Dua versi `setSpeed()`:
- `setSpeed(int speed)` — kecepatan dalam integer
- `setSpeed(double speed)` — kecepatan dalam double

## Konsep

- Function overloading: **nama sama, parameter beda**
- Compiler memilih fungsi yang sesuai berdasarkan argumen
- Overloading dapat berbeda dalam:
  - Jumlah parameter
  - Tipe parameter
- Overloading tidak bisa dibedakan hanya dari return type
