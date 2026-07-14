# 02 — Variables

Deklarasi dan penggunaan berbagai tipe data dalam C++ dengan konteks robot.

## Program

### `variables.cpp`
Mendeklarasikan variabel robot menggunakan berbagai tipe data:

| Tipe Data | Contoh Penggunaan          |
|-----------|----------------------------|
| `std::string` | nama robot, versi software |
| `int`        | ID robot, baterai          |
| `double`     | tegangan                   |
| `float`      | kecepatan                  |
| `bool`       | deteksi obstacle           |
| `char`       | perintah gerak             |
| `constexpr`  | jumlah roda, payload maks  |
| `auto`       | versi software             |

Output menampilkan spesifikasi robot dalam format tabel rapi menggunakan `std::setw`.

## Konsep

- Tipe data dasar (`int`, `double`, `float`, `bool`, `char`)
- `std::string` untuk teks
- `const` dan `constexpr` untuk nilai tetap
- `auto` untuk deduksi tipe otomatis
- Format output dengan `std::setw`, `std::left`, `std::fixed`, `std::setprecision`
