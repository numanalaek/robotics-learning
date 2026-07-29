# 01 — Hello Robot

Program pertama C++ untuk menampilkan informasi robot ke terminal.

## Empat Hal Penting

| # | Konsep | Contoh |
|---|--------|--------|
| 1 | `#include <iostream>` mengimpor library I/O | `#include <iostream>` |
| 2 | `main()` adalah titik masuk program | `int main() { }` |
| 3 | `std::cout` mencetak teks ke layar | `std::cout << "Halo";` |
| 4 | `return 0` menandakan program sukses | `return 0;` |

## Program 1 — `main.cpp`

```cpp
#include <iostream>

int main()
{
    std::cout << "==========================" << std::endl;
    std::cout << "NUIN Autonomous Robot" << std::endl;
    std::cout << "Modern C++ Learning" << std::endl;
    std::cout << "==========================" << std::endl;

    return 0;
}
```

### Output

```
==========================
NUIN Autonomous Robot
Modern C++ Learning
==========================
```

## Program 2 — `mainTest.cpp`

```cpp
#include <iostream>

int main()
{
    std::cout << "Robot Name : NUIN-AMR-01" << std::endl;
    std::cout << "Version    : v1.0" << std::endl;
    std::cout << "Language   : Modern C++" << std::endl;
    std::cout << "Battery    : 100%" << std::endl;
    std::cout << "Status     : READY" << std::endl;

    return 0;
}
```

### Output

```
Robot Name : NUIN-AMR-01
Version    : v1.0
Language   : Modern C++
Battery    : 100%
Status     : READY
```

## Command Line

```bash
# Program 1
g++ main.cpp -o main && ./main

# Program 2
g++ mainTest.cpp -o mainTest && ./mainTest
```

## Analogi

`std::cout` seperti **layar LCD robot** — apa pun yang dikirim ke sana akan tampil.

| Kode C++ | Hasil di Layar |
|----------|---------------|
| `std::cout << "Halo";` | `Halo` |
| `std::cout << 42;` | `42` |
| `std::cout << std::endl;` | Pindah baris baru |

## Latihan

1. Ubah teks "NUIN Autonomous Robot" menjadi nama robot Anda.
2. Tambahkan baris `std::cout << "Siap bergerak!" << std::endl;`
3. Ganti `std::endl` dengan `'\n'` — apa bedanya?
4. Hapus `return 0;` — apakah program tetap berjalan?
