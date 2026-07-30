# 19. Copy Constructor

## Objective

Understand that:

```cpp
Robot robot2 = robot1;
```

does not always use ordinary copying. The compiler actually calls a **special constructor** — **Copy Constructor**.

## Four Important Things About Copy Constructor

| # | Rule | Example |
|---|------|--------|
| 1 | Called when an object is created **from another object** | `Robot robot2 = robot1;` |
| 2 | Parameter **must** be `const Robot &other` (reference) | `Robot(const Robot &other)` |
| 3 | Not `Robot(Robot other)` — because that causes **recursion** | `Robot(Robot other)` ❌ |
| 4 | Copies all data members one by one | `name_(other.name_)` |

## Code — `copy_constructor.cpp`

```cpp
#include <iostream>
#include <string>

class Robot
{
private:
    std::string name_;

public:
    Robot(const std::string &name)
        : name_(name)
    {
        std::cout << "Constructor : "
                  << name_
                  << '\n';
    }

    Robot(const Robot &other)
        : name_(other.name_)
    {
        std::cout
            << "Copy Constructor : "
            << name_
            << '\n';
    }

    void print() const
    {
        std::cout
            << "Robot = "
            << name_
            << '\n';
    }
};

int main()
{
    Robot robot1("NUIN-AMR-01");

    std::cout << '\n';

    Robot robot2 = robot1;

    std::cout << '\n';

    robot1.print();
    robot2.print();
}
```

## Output

```
Constructor : NUIN-AMR-01

Copy Constructor : NUIN-AMR-01

Robot = NUIN-AMR-01
Robot = NUIN-AMR-01
```

## Visualization

```
Robot robot1("NUIN-AMR-01");

        │
        ▼

+----------------+
| name_ = NUIN   |
+----------------+

        │
        │
Robot robot2 = robot1;
        │
        ▼

Copy Constructor

        │

+----------------+
| name_ = NUIN   |
+----------------+

A new object is created.
The entire contents of robot1 are copied to robot2.
```

## Why parameter `const Robot &other`?

Notice the signature:

```cpp
Robot(const Robot &other);   // ✅ benar
```

Not:

```cpp
Robot(Robot other);          // ❌ WRONG!
```

**Why?**

If written as `Robot(Robot other)`, then to call the Copy Constructor, the compiler must **copy the object first**. Copying the object means **calling the Copy Constructor again**, which then must copy the object again, and so on — causing **infinite recursion**.

Therefore the parameter **must be a reference**. And because the source object must not be modified, `const` is used.

This is one of the **most important uses of `const reference` in all of C++**.

## Difference Between Regular Constructor vs Copy Constructor

| Constructor | Copy Constructor |
|-------------|------------------|
| `Robot(const std::string &name)` | `Robot(const Robot &other)` |
| Receives a **string** as source | Receives **another object** as source |
| Initializes from a new value | Copies from an existing object |
| `Robot robot1("NUIN");` | `Robot robot2 = robot1;` |

## Connection to ROS 2

In ROS 2 you will often see patterns like:

```cpp
Robot(const Robot &) = delete;
```

or

```cpp
Node(const Node &) = delete;
```

**Why?**

Because many ROS 2 objects cannot be arbitrarily copied — for example publishers, subscribers, mutexes, threads, sockets, and system resources. By understanding Copy Constructor now, when you see ROS 2 code like that you will immediately understand its purpose.

## Command Line

```bash
g++ copy_constructor.cpp -o copy_constructor && ./copy_constructor
```

## Learning Objectives

By the end of this chapter, you are expected to understand:

- ✅ What Copy Constructor is
- ✅ When Copy Constructor is called
- ✅ Why its parameter type is `const Robot &other`
- ✅ The difference between regular constructor and Copy Constructor
- ✅ Why Copy Constructor is very important in modern C++ object design

## Next Steps

After this chapter, the most natural next step is **Copy Assignment Operator** (`operator=`). That is where you will understand the difference between:

```cpp
Robot robot2 = robot1;   // Copy Constructor
```

```cpp
Robot robot2;
robot2 = robot1;         // Copy Assignment Operator
```

The difference looks small in code, but internally they are different mechanisms and are an important foundation before learning **move semantics** and **smart pointers**.

## Exercises

1. Remove the Copy Constructor from the class — compile. Does the program still run? (Compiler creates implicit copy constructor).
2. Change `Robot(const Robot &other)` to `Robot(Robot other)` — compile and see the error.
3. Add `std::cout << "Address other: " << &other << '\n';` inside the Copy Constructor — is the address of `other` the same as `robot1`?
4. Create a function `void printRobot(Robot r)` — call it with `robot1`. Which constructor is called?
