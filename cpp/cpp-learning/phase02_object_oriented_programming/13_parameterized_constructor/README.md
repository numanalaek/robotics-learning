# 13. Parameterized Constructor

**Parameterized Constructor** adalah constructor yang menerima parameter sehingga nilai awal data member suatu objek dapat diinisialisasi secara langsung saat objek dibuat.

## Contoh 1: `parameterized_constructor.cpp`

Mendefinisikan kelas `Robot` dengan constructor berparameter untuk menginisialisasi `battery`, `voltage`, dan `mode`.

```cpp
Robot robot(85, 24.3, "AUTO");
```

Output:

```
Battery : 85%
Voltage : 24.3 V
Mode    : AUTO
```

## Contoh 2: `parameterized_constructor_test1.cpp`

Mendemonstrasikan pembuatan **beberapa objek** dengan nilai yang berbeda menggunakan parameterized constructor. Setiap objek `Robot` memiliki `id`, `battery`, dan `mode` yang berbeda.

```cpp
Robot robot1(1, 95, "AUTO");
Robot robot2(2, 60, "MANUAL");
```

Output:

```
Robot 1 | Battery 95% | AUTO
Robot 2 | Battery 60% | MANUAL
```

## Poin Penting

- Parameterized constructor memungkinkan inisialisasi **berbeda** untuk tiap objek.
- Menggunakan **initializer list** (`: member(value)`) lebih efisien daripada assignment di dalam body constructor.
- Dengan parameterized constructor, kita tidak perlu memanggil setter terpisah setelah objek dibuat.
