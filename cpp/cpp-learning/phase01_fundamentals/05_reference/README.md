# 05 — Reference

Perbedaan pass by value, pass by reference, dan pass by const reference.

## Empat Hal Penting tentang Reference

| # | Konsep | Contoh |
|---|--------|--------|
| 1 | **Pass by value** — fungsi menerima **salinan** (copy) | `void func(int x)` |
| 2 | **Pass by reference** — fungsi menerima **alias** (sama dengan asli) | `void func(int &x)` |
| 3 | **Pass by const ref** — efisien (tanpa copy) + aman (read-only) | `void func(const int &x)` |
| 4 | Reference adalah **nama lain**, bukan pointer — alamatnya SAMA | `&ref == &battery` |

## Tabel Perbandingan

| Metode | Sintaks | Copy? | Ubah Asli? | Efisien? |
|--------|---------|-------|------------|----------|
| Pass by value | `T x` | Ya | Tidak | Boros (untuk objek besar) |
| Pass by reference | `T &x` | Tidak | Ya | Ya |
| Pass by const ref | `const T &x` | Tidak | Tidak | Ya |

## Program 1 — `pass_by_value.cpp`

```cpp
#include <iostream>
#include <string>

void printName(std::string name)
{
    std::cout << "Alamat di fungsi : " << &name << '\n';
    std::cout << "Isi di fungsi    : " << name << '\n';
    name = "MODIFIED";
    std::cout << "Setelah diubah   : " << name << '\n';
}

int main()
{
    std::string robot = "NUIN-AMR-01";
    std::cout << "Alamat di main   : " << &robot << '\n';
    std::cout << "Isi di main      : " << robot << '\n';

    printName(robot);

    std::cout << "Isi di main setelah fungsi : " << robot << '\n';
    return 0;
}
```

### Output

```
Alamat di main   : 0x7ffff723d1d0
Isi di main      : NUIN-AMR-01
Alamat di fungsi : 0x7ffff723d1f0   ← berbeda!
Isi di fungsi    : NUIN-AMR-01
Setelah diubah   : MODIFIED
Isi di main setelah fungsi : NUIN-AMR-01  ← tidak berubah!
```

## Program 2 — `pass_by_reference.cpp`

```cpp
#include <iostream>
#include <string>

void printName(std::string &name)
{
    std::cout << "Alamat di fungsi : " << &name << '\n';
    std::cout << "Isi di fungsi    : " << name << '\n';
    name = "MODIFIED";
    std::cout << "Setelah diubah   : " << name << '\n';
}

int main()
{
    std::string robot = "NUIN-AMR-01";
    std::cout << "Alamat di main   : " << &robot << '\n';
    std::cout << "Isi di main      : " << robot << '\n';

    printName(robot);

    std::cout << "Isi di main setelah fungsi : " << robot << '\n';
    return 0;
}
```

### Output

```
Alamat di main   : 0x7ffcaf9e4c80
Isi di main      : NUIN-AMR-01
Alamat di fungsi : 0x7ffcaf9e4c80   ← SAMA!
Isi di fungsi    : NUIN-AMR-01
Setelah diubah   : MODIFIED
Isi di main setelah fungsi : MODIFIED  ← berubah!
```

## Program 3 — `const_reference.cpp`

```cpp
#include <iostream>
#include <string>

void printName(const std::string &name)
{
    std::cout << "Alamat di fungsi : " << &name << '\n';
    std::cout << "Isi di fungsi    : " << name << '\n';
    // name = "MODIFIED";  // ERROR: const reference read-only
}

int main()
{
    std::string robot = "NUIN-AMR-01";
    std::cout << "Alamat di main   : " << &robot << '\n';
    std::cout << "Isi di main      : " << robot << '\n';

    printName(robot);

    std::cout << "Isi di main setelah fungsi : " << robot << '\n';
    return 0;
}
```

### Output

```
Alamat di main   : 0x7ffc2ad60350
Isi di main      : NUIN-AMR-01
Alamat di fungsi : 0x7ffc2ad60350   ← SAMA
Isi di fungsi    : NUIN-AMR-01
Isi di main setelah fungsi : NUIN-AMR-01  ← tetap
```

## Command Line

```bash
g++ pass_by_value.cpp -o pass_by_value && ./pass_by_value
g++ pass_by_reference.cpp -o pass_by_reference && ./pass_by_reference
g++ const_reference.cpp -o const_reference && ./const_reference
g++ reference_test1.cpp -o reference_test1 && ./reference_test1
g++ reference_test2.cpp -o reference_test2 && ./reference_test2
```

## Analogi

| Metode | Analogi |
|--------|---------|
| **Pass by value** | Fotokopi datasheet — coretan di fotokopi tidak merusak asli |
| **Pass by reference** | Meminjamkan datasheet asli — coretan akan merusak asli |
| **Pass by const ref** | Membaca datasheet di rak — tidak boleh disentuh, tapi tidak perlu difotokopi |

## Aturan Praktis

| Situasi | Gunakan |
|---------|---------|
| Ingin mengubah variabel asli | `T &x` (reference) |
| Hanya perlu membaca, tipe kecil (int, double) | `T x` (by value) |
| Hanya perlu membaca, tipe besar (string, vector) | `const T &x` (const ref) |

## Latihan

1. Di `pass_by_value.cpp`, buktikan alamat berbeda dengan mencetak `&name` dan `&robot`.
2. Di `pass_by_reference.cpp`, apa yang terjadi jika `&name == &robot`?
3. Compile `const_reference_test.cpp` — baca pesan error-nya.
4. Di `reference_test2.cpp`, buktikan bahwa `&ref == &battery` (reference tidak punya alamat sendiri).
