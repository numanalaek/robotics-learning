# 18. Destructor dalam C++

## Four Important Things About Destructor

| # | Rule | Example |
|---|------|--------|
| 1 | Called **automatically** when an object **goes out of scope** | `{ Robot r; }` → `~Robot()` runs at `}` |
| 2 | Name is **exactly the same** as the class name, prefixed with `~` | `~Robot()` |
| 3 | **Has no return type** and **cannot be overloaded** | `~Robot();` ✅ | `~Robot(int);` ❌ |
| 4 | **Cleans up resources** (memory, file, mutex, etc.) | `delete[] data;` inside `~Robot()` |

## Code

```cpp
#include <iostream>

class Robot
{
public:
    Robot()
    {
        std::cout << "Constructor\n";
    }

    ~Robot()
    {
        std::cout << "Destructor\n";
    }
};

int main()
{
    Robot robot1;

    {
        Robot robot2;
    }

    Robot robot3;
}
```

## Output

```
Constructor
Constructor
Destructor
Constructor
Destructor
Destructor
```

### Output order explanation:

| Step | Code | Output | Description |
|------|------|--------|-------------|
| 1 | `Robot robot1;` | `Constructor` | robot1 created in `main()` scope |
| 2 | `Robot robot2;` | `Constructor` | robot2 created in block `{ }` scope |
| 3 | `}` | `Destructor` | **robot2 destroyed** when leaving block scope |
| 4 | `Robot robot3;` | `Constructor` | robot3 created in `main()` scope |
| 5 | `return 0;` | `Destructor` | robot3 destroyed (reverse order: robot3 first) |
| 6 | `return 0;` | `Destructor` | robot1 destroyed |

## Command Line

```bash
# Kompilasi
g++ -std=c++11 -o destructor destructor.cpp

# Jalankan
./destructor

# Kompilasi + jalankan sekali
g++ -std=c++11 -o destructor destructor.cpp && ./destructor
```

## Lifetime & Scope

Destructor proves the fundamental **lifetime** rule in C++:

```
{                            // ← masuk scope
    Robot r;                 // Constructor → r "hidup"
    // r bisa digunakan di sini
}                            // ← keluar scope → Destructor → r "mati"
```

Local variables live from the point of declaration to the end of their `{ }` scope. The destructor **is guaranteed to be called**, even if there is a `return`, `break`, or exception — this is the RAII guarantee.

## Analogy

Destructor is like a **death certificate** — when an object "dies", all its resources are cleaned up.

| Object | Born | Dies |
|-------|-------|------|
| `Robot robot1` | `Constructor` | `Destructor` (akhir main) |
| `Robot robot2` | `Constructor` | `Destructor` (akhir scope `{ }`) |
| `Robot robot3` | `Constructor` | `Destructor` (akhir main) |

Without a destructor → resources leak (memory leak, file not closed, mutex not unlocked).

## Exercises

1. Remove the destructor → compile → no error (compiler creates default). Does the output change?
2. Add `Robot robot4;` at the end of `main()` scope — predict the output before running.
3. Wrap `robot3` in its own block scope → what happens to the output order?
4. Add `static Robot robot_static;` — when is the static destructor called?
