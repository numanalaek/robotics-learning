# 03 — Memory & Pointer

Understanding variable memory addresses and pointer usage in C++.

## Four Important Things about Memory & Pointer

| # | Concept | Example |
|---|--------|--------|
| 1 | Every variable has a **unique address** in memory | `&battery` → `0x7fff...` |
| 2 | `&` (address-of) gets the variable's address | `int *ptr = &battery;` |
| 3 | `*` (dereference) accesses the value at the address | `*ptr = 50;` → battery changes |
| 4 | Pointer stores an **address**, not a value | `ptr` holds address, `*ptr` holds value |

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

## Memory Diagram

```
Variable battery (int)
  Address: 0x7fff...
  Value : 100

Pointer ptr (int*)
  Address: 0x7fff... (different)
  Value : 0x7fff... (same as &battery)

Dereference *ptr → accesses value 100 at that address
```

## Command Line

```bash
g++ memory.cpp -o memory && ./memory
g++ address_pointer.cpp -o address_pointer && ./address_pointer
g++ pointer_test.cpp -o pointer_test && ./pointer_test
```

## Analogy

Memory is like a **spare parts storage location in a robot warehouse**.

| C++ Concept | Warehouse Analogy |
|-----------|----------------|
| Variable `battery` | Parts box containing "100" |
| Address `&battery` | Shelf label: "Building A, Shelf 3, Column 5" |
| Pointer `ptr` | Note card with the shelf location written on it |
| Dereference `*ptr` | Go to the shelf according to the note, take the contents |

## Exercises

1. Create a pointer to `double voltage` — what is the pointer type?
2. Change `battery` through a pointer several times — what happens to the `ptr` address?
3. Compare `&ptr` with `&battery` — are they the same? Why?
4. Create two pointers to the same variable — does `*ptr1 == *ptr2`?
