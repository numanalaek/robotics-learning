# 03 — Memory

Memahami alamat memori variabel dan penggunaan pointer dalam C++.

## Program

### `memory.cpp`
Menampilkan nilai dan alamat memori dari variabel `int`, `double`, dan `char`. Alamat `char` dicetak dengan `static_cast<void*>` karena `char` dianggap string oleh `<<`.

### `address_pointer.cpp`
Demonstrasi pointer:
- Menyimpan alamat variabel ke pointer (`int *ptr = &battery`)
- Mengakses nilai melalui pointer dengan dereference (`*ptr`)
- Mengubah nilai variabel asli melalui pointer

### `pointer_test.cpp`
Latihan mengubah nilai baterai berkali-kali melalui pointer untuk membuktikan bahwa pointer mengakses variabel asli.

## Konsep

- `&` (address-of) — mendapatkan alamat memori
- `*` (dereference) — mengakses nilai dari alamat
- Pointer menyimpan alamat, bukan nilai
- Mengubah nilai melalui pointer = mengubah variabel asli
- `static_cast<void*>` untuk menampilkan alamat `char`
