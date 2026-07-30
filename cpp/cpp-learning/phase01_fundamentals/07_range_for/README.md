# 07 — Range-based For Loop

Range-based `for` loop (C++11) for simpler and safer array iteration.

## Four Important Things about Range-based For

| # | Concept | Example |
|---|--------|--------|
| 1 | Automatic iteration without **index** | `for (int x : arr)` |
| 2 | `T x : arr` — `x` is a **copy** (safe, but wasteful) | `for (int sensor : sensors)` |
| 3 | `T &x : arr` — `x` is a **reference** (can modify original) | `for (int &sensor : sensors)` |
| 4 | `const T &x : arr` — efficient + safe (read-only) | `for (const int &sensor : sensors)` |

## Code — `range_for.cpp`

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
    sensor = 0;  // Does NOT change the original array
}
```

### 2. Reference — `for (int &sensor : sensors)`

```cpp
for (int &sensor : sensors) {
    sensor = 0;  // MODIFIES the original array
}
```

### 3. Const Reference — `for (const int &sensor : sensors)` ✅ BEST

```cpp
for (const int &sensor : sensors) {
    std::cout << sensor;  // Read only, cannot modify
}
```

## Index-based vs Range-based Comparison

| Aspect | Index-based `for` | Range-based `for` |
|-------|-------------------|-------------------|
| Syntax | `for (int i=0; i<N; i++)` | `for (int x : arr)` |
| Needs index | Yes | No |
| Element access | `arr[i]` | Directly `x` |
| Modify element | `arr[i] = n` | `T &x : arr` |
| Access index i | `i` | Cannot |
| Reverse loop | `i--` | Cannot |

## Command Line

```bash
g++ range_for.cpp -o range_for && ./range_for
g++ range_for_test1.cpp -o range_for_test1 && ./range_for_test1
g++ range_for_test3.cpp -o range_for_test3 && ./range_for_test3  # buktikan copy
g++ range_for_test4.cpp -o range_for_test4 && ./range_for_test4  # reference
g++ range_for_test5.cpp -o range_for_test5 && ./range_for_test5  # const ref
```

## Analogy

| Variant | Analogy |
|--------|---------|
| `for (T x : arr)` | Photocopy of a data sheet — scribbles don't damage the original |
| `for (T &x : arr)` | Holding the original component — changes damage the original |
| `for (const T &x : arr)` | Reading a display — cannot be touched, but without photocopy |

## Exercises

1. In `range_for_test3.cpp`, prove that `sensor` is a copy (original array doesn't change).
2. Modify `range_for_test4.cpp` — use `int &sensor` and set all to 99. Does the array change?
3. Compile `range_for_test5.cpp` — try adding `sensor = 0;` inside the loop. What error do you get?
4. Create a range-based loop for a `double` array — what type is suitable for `const &`?
