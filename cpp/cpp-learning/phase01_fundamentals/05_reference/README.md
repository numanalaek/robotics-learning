# 05 — Reference

The differences between pass by value, pass by reference, and pass by const reference.

## Four Important Things about Reference

| # | Concept | Example |
|---|--------|--------|
| 1 | **Pass by value** — function receives a **copy** | `void func(int x)` |
| 2 | **Pass by reference** — function receives an **alias** (same as original) | `void func(int &x)` |
| 3 | **Pass by const ref** — efficient (no copy) + safe (read-only) | `void func(const int &x)` |
| 4 | Reference is **another name**, not a pointer — addresses are the SAME | `&ref == &battery` |

## Comparison Table

| Method | Syntax | Copy? | Modify Original? | Efficient? |
|--------|---------|-------|------------|----------|
| Pass by value | `T x` | Yes | No | Wasteful (for large objects) |
| Pass by reference | `T &x` | No | Yes | Yes |
| Pass by const ref | `const T &x` | No | No | Yes |

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

## Analogy

| Method | Analogy |
|--------|---------|
| **Pass by value** | Photocopy of a datasheet — scribbles on the copy don't damage the original |
| **Pass by reference** | Lending the original datasheet — scribbles will damage the original |
| **Pass by const ref** | Reading the datasheet on the shelf — can't touch it, but no need to photocopy |

## Practical Guidelines

| Situation | Use |
|---------|---------|
| Want to modify the original variable | `T &x` (reference) |
| Only need to read, small type (int, double) | `T x` (by value) |
| Only need to read, large type (string, vector) | `const T &x` (const ref) |

## Exercises

1. In `pass_by_value.cpp`, prove the addresses are different by printing `&name` and `&robot`.
2. In `pass_by_reference.cpp`, what happens when `&name == &robot`?
3. Compile `const_reference_test.cpp` — read the error message.
4. In `reference_test2.cpp`, prove that `&ref == &battery` (reference doesn't have its own address).
