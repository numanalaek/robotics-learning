# 01 — Hello Robot

The first C++ program to display robot information to the terminal.

## Four Important Things

| # | Concept | Example |
|---|--------|--------|
| 1 | `#include <iostream>` imports the I/O library | `#include <iostream>` |
| 2 | `main()` is the program entry point | `int main() { }` |
| 3 | `std::cout` prints text to the screen | `std::cout << "Hello";` |
| 4 | `return 0` indicates the program succeeded | `return 0;` |

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

## Analogy

`std::cout` is like a **robot LCD screen** — whatever is sent to it will be displayed.

| C++ Code | Result on Screen |
|----------|---------------|
| `std::cout << "Hello";` | `Hello` |
| `std::cout << 42;` | `42` |
| `std::cout << std::endl;` | New line |

## Exercises

1. Change the text "NUIN Autonomous Robot" to your robot's name.
2. Add the line `std::cout << "Ready to move!" << std::endl;`
3. Replace `std::endl` with `'\n'` — what's the difference?
4. Remove `return 0;` — does the program still run?
