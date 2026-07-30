# 08 — Function Overloading

Defining multiple functions with the **same name** but **different parameters**.

## Four Important Things about Function Overloading

| # | Concept | Example |
|---|--------|--------|
| 1 | Function name **same**, parameters **different** | `void printStatus();` vs `void printStatus(int);` |
| 2 | Compiler selects the **matching** function based on arguments | `printStatus(80)` → calls `int` version |
| 3 | Can differ in **number** or **type** of parameters | `(int)` vs `(int, double)` |
| 4 | Cannot be distinguished only by **return type** | `int foo();` and `void foo();` ❌ error |

## Code — `function_overloading.cpp`

```cpp
#include <iostream>

void printStatus()
{
    std::cout << "Robot READY\n";
}

void printStatus(int battery)
{
    std::cout << "Battery : " << battery << "%\n";
}

void printStatus(int battery, double voltage)
{
    std::cout << "Battery : " << battery << "%\n";
    std::cout << "Voltage : " << voltage << " V\n";
}

int main()
{
    printStatus();
    printStatus(80);
    printStatus(80, 24.5);
    return 0;
}
```

## Output

```
Robot READY
Battery : 80%
Battery : 80%
Voltage : 24.5 V
```

## How Overloading Works

```
printStatus()           → calls void printStatus()
printStatus(80)         → calls void printStatus(int)
printStatus(80, 24.5)   → calls void printStatus(int, double)
```

The compiler matches the **number** and **type** of arguments with available parameters.

## Other Programs

| File | Overloading |
|------|-------------|
| `function_overloading_test1.cpp` | `move()` and `move(int step)` |
| `function_overloading_test2.cpp` | `setSpeed(int)` and `setSpeed(double)` |

## Overloading Requirements

| Allowed | Not Allowed |
|------|------------|
| Different number of parameters | Different return type only |
| Different parameter types | Same parameters, different names |
| `(int)` vs `(double)` | `(int)` vs `(int)` — duplicate |

## Command Line

```bash
g++ function_overloading.cpp -o function_overloading && ./function_overloading
g++ function_overloading_test1.cpp -o function_overloading_test1 && ./function_overloading_test1
g++ function_overloading_test2.cpp -o function_overloading_test2 && ./function_overloading_test2
```

## Analogy

Overloading is like a **universal remote control** — the "ON" button means different things depending on the target device.

| Call | Remote | Action |
|-----------|--------|------|
| `printStatus()` | Press "Status" without device | "Robot READY" |
| `printStatus(80)` | Press "Status" → TV | "Battery: 80%" |
| `printStatus(80, 24.5)` | Press "Status" → AC | "Battery: 80%, Voltage: 24.5V" |

## Exercises

1. Add overload `printStatus(double voltage)` — only print voltage. What happens?
2. Create overload `printStatus(int battery, bool emergency)`.
3. Compile `printStatus(80, 24);` — which overload is called? Why?
4. Can `void printStatus(int a)` and `void printStatus(int b)` be overloaded? Why?
