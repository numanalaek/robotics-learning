# 07 — Range-based For Loop

Penggunaan range-based `for` loop (C++11) untuk iterasi array dengan lebih sederhana dan aman.

## Program

### `range_for.cpp`
Memonitor 6 sel baterai (dalam volt). Menghitung min, max, rata-rata, dan mendeteksi sel lemah (`LOW CELL`).

### `range_for_test1.cpp`
Range-based for untuk membaca 8 sensor jarak.

### `range_for_test2.cpp`
Menjumlahkan nilai sensor dan menghitung rata-rata.

### `range_for_test3.cpp`
Membuktikan bahwa `for (int sensor : array)` membuat **copy** — array asli tidak berubah saat elemen dimodifikasi.

### `range_for_test4.cpp`
Menggunakan `for (int &sensor : array)` — array asli **berubah** karena reference.

### `range_for_test5.cpp`
Menggunakan `for (const int &sensor : array)` — paling efisien (tanpa copy) dan aman (read-only).

## Konsep

| Sintaks                | Copy? | Ubah Asli? | Efisien? |
|------------------------|-------|------------|----------|
| `for (T x : arr)`      | Ya    | Tidak      | Boros    |
| `for (T &x : arr)`     | Tidak | Ya         | Ya       |
| `for (const T &x : arr)` | Tidak | Tidak    | Ya       |

- Range-based for lebih sederhana daripada index-based for
- `std::size()` untuk mendapatkan panjang array
- `std::fixed` + `precision()` untuk format angka desimal
