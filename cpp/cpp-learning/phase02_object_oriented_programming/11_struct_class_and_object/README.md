# 11 — Struct, Class & Object

Memahami perbedaan struct dan class, serta konsep blueprint dan object dalam C++.

## Program

### `robot_struct.cpp`
Struct `Robot` dengan 4 data member. Dua object (`robot1`, `robot2`) dengan data berbeda.

### `robot_class.cpp`
Class `Robot` yang identik dengan struct, tetapi perlu `public:` eksplisit.

### `struct_test.cpp`
Latihan dasar struct dengan 3 member dan satu object.

### `class_vs_struct.cpp`
Perbandingan langsung struct vs class secara berdampingan dalam satu program.

### `class_test.cpp`
Latihan class dengan 2 object dan demonstrasi bahwa tiap object punya data sendiri.

## Konsep

- **Struct / Class** — blueprint atau tipe data yang mendefinisikan bentuk Robot
- **Object** — instance nyata yang dibuat berdasarkan blueprint (`Robot robot1;`)
- **Data member** — variabel milik object, diakses dengan titik (`robot1.battery`)
- **Default access** — struct = `public`, class = `private`
- Setiap object punya **salinan data sendiri** — mengubah object lain tidak memengaruhinya
