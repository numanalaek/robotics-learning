# 09 — Default Parameters

Memberikan nilai default pada parameter fungsi sehingga bisa dipanggil dengan jumlah argumen yang bervariasi.

## Program

### `default_parameters.cpp`
Fungsi `robotStatus()` dengan tiga parameter default:
```cpp
void robotStatus(
    int battery = 100,
    double voltage = 24.0,
    bool obstacle = false);
```

Empat cara pemanggilan:

| Panggilan                          | battery | voltage | obstacle |
|------------------------------------|---------|---------|----------|
| `robotStatus()`                    | 100     | 24.0    | false    |
| `robotStatus(80)`                  | 80      | 24.0    | false    |
| `robotStatus(80, 23.5)`            | 80      | 23.5    | false    |
| `robotStatus(80, 23.5, true)`      | 80      | 23.5    | true     |

### `default_parameters_test1.cpp`
Fungsi `printStatus()` dengan default `battery = 100`.

### `default_parameters_test2.cpp`
Fungsi `moveRobot()` dengan default `distance = 1` dan `speed = 1.0`.

## Konsep

- Default parameter ditulis di **deklarasi/definisi** (biasanya di header)
- Argumen diisi dari kiri ke kanan — tidak bisa skip parameter tengah
- Default parameter memungkinkan fleksibilitas tanpa overloading
- Format output dengan `std::fixed` + `std::setprecision(1)`
