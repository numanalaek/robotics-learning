# 04 — Functions

Implementasi fungsi dalam C++ untuk mengendalikan robot bergerak di bidang 2D.

## Program

### `robot_control.cpp`
Program simulasi kontrol robot dengan perintah `w` (maju), `s` (mundur), `a` (kiri), `d` (kanan), `q` (keluar).

**Fungsi:**
| Fungsi              | Keterangan                              |
|---------------------|------------------------------------------|
| `printHeader()`     | Menampilkan header program               |
| `printStatus()`     | Menampilkan posisi, arah, baterai        |
| `moveForward()`     | Maju sesuai arah, kurangi baterai        |
| `moveBackward()`    | Mundur sesuai arah, kurangi baterai      |
| `turnLeft()`        | Belok kiri (ubah arah), kurangi baterai  |
| `turnRight()`       | Belok kanan (ubah arah), kurangi baterai |
| `consumeBattery()`  | Kurangi baterai 1% setiap gerakan        |

## Konsep

- Deklarasi dan definisi fungsi
- Parameter dan return value
- **Pass by reference** — `int &battery` mengubah variabel asli
- Array sebagai lookup table (`const char *arah[]`)
- `switch-case` untuk logika arah dan perintah
