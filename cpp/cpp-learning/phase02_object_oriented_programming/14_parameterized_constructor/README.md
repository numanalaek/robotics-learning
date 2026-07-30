# 14. Parameterized Constructor

**Parameterized Constructor** is a constructor that accepts parameters so that the initial values of an object's data members can be initialized directly when the object is created.

## Example 1: `parameterized_constructor.cpp`

Defines a `Robot` class with a parameterized constructor to initialize `battery`, `voltage`, and `mode`.

```cpp
Robot robot(85, 24.3, "AUTO");
```

Output:

```
Battery : 85%
Voltage : 24.3 V
Mode    : AUTO
```

## Example 2: `parameterized_constructor_test1.cpp`

Demonstrates creating **multiple objects** with different values using a parameterized constructor. Each `Robot` object has a different `id`, `battery`, and `mode`.

```cpp
Robot robot1(1, 95, "AUTO");
Robot robot2(2, 60, "MANUAL");
```

Output:

```
Robot 1 | Battery 95% | AUTO
Robot 2 | Battery 60% | MANUAL
```

## Key Points

- Parameterized constructor allows **different** initialization for each object.
- Using **initializer list** (`: member(value)`) is more efficient than assignment inside the constructor body.
- With a parameterized constructor, we don't need to call separate setters after the object is created.
