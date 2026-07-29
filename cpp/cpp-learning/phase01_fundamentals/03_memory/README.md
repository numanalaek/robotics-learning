# 03 — Memory & Pointer

Memahami alamat memori variabel dan penggunaan pointer dalam C++.

## Empat Hal Penting tentang Memori & Pointer

| # | Konsep | Contoh |
|---|--------|--------|
| 1 | Setiap variabel punya **alamat unik** di memori | `&battery` → `0x7fff...` |
| 2 | `&` (address-of) mengambil alamat variabel | `int *ptr = &battery;` |
| 3 | `*` (dereference) mengakses nilai dari alamat | `*ptr = 50;` → battery berubah |
| 4 | Pointer menyimpan **alamat**, bukan nilai | `ptr` isi alamat, `*ptr` isi nilai |

## Program 1 — `memory.cpp`

```cpp
#include <iostream>

int main()
{
    int battery = 100;
    double voltage = 24.6;
    char command = 'W';

    std::cout << "battery : " << battery << '\n';
    std::cout << "voltage : " << voltage << '\n';
    std::cout << "command : " << command << '\n';

    std::cout << "\nAddress\n";
    std::cout << "battery : " << &battery << '\n';
    std::cout << "voltage : " << &voltage << '\n';
    std::cout << "command : " << static_cast<void *>(&command) << '\n';

    return 0;
}
```

### Output

```
battery : 100
voltage : 24.6
command : W

Address
battery : 0x7ffd04a0c3fc
voltage : 0x7ffd04a0c400
command : 0x7ffd04a0c3fb
```

## Program 2 — `address_pointer.cpp`

```cpp
#include <iostream>

int main()
{
    int battery = 100;

    std::cout << "battery : " << battery << '\n';
    std::cout << "&battery : " << &battery << '\n';

    int *ptr = &battery;

    std::cout << "ptr     : " << ptr << '\n';
    std::cout << "*ptr    : " << *ptr << '\n';

    *ptr = 50;

    std::cout << battery << '\n';

    return 0;
}
```

### Output

```
battery : 100
&battery : 0x7fff0b18273c
ptr     : 0x7fff0b18273c
*ptr    : 100
50
```

## Diagram Memori

```
Variabel battery (int)
  Alamat: 0x7fff...
  Nilai : 100

Pointer ptr (int*)
  Alamat: 0x7fff... (berbeda)
  Nilai : 0x7fff... (sama dengan &battery)

Dereference *ptr → mengakses nilai 100 di alamat tersebut
```

## Command Line

```bash
g++ memory.cpp -o memory && ./memory
g++ address_pointer.cpp -o address_pointer && ./address_pointer
g++ pointer_test.cpp -o pointer_test && ./pointer_test
```

## Analogi

Memory seperti **lokasi penyimpanan suku cadang di gudang robot**.

| Konsep C++ | Analogi Gudang |
|-----------|----------------|
| Variabel `battery` | Kotak suku cadang berisi "100" |
| Alamat `&battery` | Label rak: "Gedung A, Rak 3, Kolom 5" |
| Pointer `ptr` | Kartu catatan yang berisi tulisan lokasi rak |
| Dereference `*ptr` | Pergi ke rak sesuai catatan, ambil isinya |

## Latihan

1. Buat pointer ke `double voltage` — apa tipe pointer-nya?
2. Ubah `battery` melalui pointer beberapa kali — apa yang terjadi pada alamat `ptr`?
3. Bandingkan `&ptr` dengan `&battery` — apakah sama? Mengapa?
4. Buat dua pointer ke variabel yang sama — apakah `*ptr1 == *ptr2`?
