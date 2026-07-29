# 07 — Range-based For Loop

Range-based `for` loop (C++11) untuk iterasi array yang lebih sederhana dan aman.

## Empat Hal Penting tentang Range-based For

| # | Konsep | Contoh |
|---|--------|--------|
| 1 | Iterasi otomatis tanpa **indeks** | `for (int x : arr)` |
| 2 | `T x : arr` — `x` adalah **copy** (aman, tapi boros) | `for (int sensor : sensors)` |
| 3 | `T &x : arr` — `x` adalah **reference** (bisa ubah asli) | `for (int &sensor : sensors)` |
| 4 | `const T &x : arr` — efisien + aman (baca saja) | `for (const int &sensor : sensors)` |

## Kode — `range_for.cpp`

```cpp
#include <iostream>
#include <iterator>

int main()
{
    double cells[] = {3.21, 3.19, 3.24, 3.18, 3.22, 3.20};
    constexpr double LOW_CELL_LIMIT = 3.20;

    double min = cells[0];
    double max = cells[0];
    double sum = 0;
    bool has_low_cell = false;

    for (const double &cell : cells)
    {
        if (cell < min) min = cell;
        if (cell > max) max = cell;
        sum += cell;
        if (cell < LOW_CELL_LIMIT) has_low_cell = true;
    }

    double avg = sum / std::size(cells);

    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << "Min: " << min << " V\n";
    std::cout << "Max: " << max << " V\n";
    std::cout << "Avg: " << avg << " V\n";

    if (has_low_cell)
        std::cout << "LOW CELL\n";
    else
        std::cout << "BATTERY NORMAL\n";

    return 0;
}
```

## Output

```
Min: 3.18 V
Max: 3.24 V
Avg: 3.21 V
LOW CELL
```

## Tiga Varian Range-based For

### 1. Copy — `for (int sensor : sensors)`

```cpp
for (int sensor : sensors) {
    sensor = 0;  // Tidak mengubah array asli
}
```

### 2. Reference — `for (int &sensor : sensors)`

```cpp
for (int &sensor : sensors) {
    sensor = 0;  // MENGUBAH array asli
}
```

### 3. Const Reference — `for (const int &sensor : sensors)` ✅ BEST

```cpp
for (const int &sensor : sensors) {
    std::cout << sensor;  // Baca saja, tidak bisa ubah
}
```

## Perbandingan Index-based vs Range-based

| Aspek | Index-based `for` | Range-based `for` |
|-------|-------------------|-------------------|
| Sintaks | `for (int i=0; i<N; i++)` | `for (int x : arr)` |
| Butuh indeks | Ya | Tidak |
| Akses elemen | `arr[i]` | Langsung `x` |
| Ubah elemen | `arr[i] = n` | `T &x : arr` |
| Akses index i | `i` | Tidak bisa |
| Loop mundur | `i--` | Tidak bisa |

## Command Line

```bash
g++ range_for.cpp -o range_for && ./range_for
g++ range_for_test1.cpp -o range_for_test1 && ./range_for_test1
g++ range_for_test3.cpp -o range_for_test3 && ./range_for_test3  # buktikan copy
g++ range_for_test4.cpp -o range_for_test4 && ./range_for_test4  # reference
g++ range_for_test5.cpp -o range_for_test5 && ./range_for_test5  # const ref
```

## Analogi

| Varian | Analogi |
|--------|---------|
| `for (T x : arr)` | Fotokopi lembar data — coretan tidak merusak asli |
| `for (T &x : arr)` | Memegang komponen asli — perubahan merusak asli |
| `for (const T &x : arr)` | Membaca display — tidak bisa disentuh, tapi tanpa fotokopi |

## Latihan

1. Di `range_for_test3.cpp`, buktikan bahwa `sensor` adalah copy (array asli tidak berubah).
2. Ubah `range_for_test4.cpp` — pakai `int &sensor` dan set semua ke 99. Apakah array berubah?
3. Compile `range_for_test5.cpp` — coba tambah `sensor = 0;` di dalam loop. Apa error-nya?
4. Buat loop range-based untuk array `double` — tipe apa yang cocok untuk `const &`?
