# 19. Copy Constructor

## Tujuan

Memahami bahwa:

```cpp
Robot robot2 = robot1;
```

tidak selalu menggunakan copy biasa. Compiler sebenarnya memanggil sebuah **constructor khusus** — **Copy Constructor**.

## Empat Hal Penting tentang Copy Constructor

| # | Aturan | Contoh |
|---|--------|--------|
| 1 | Dipanggil saat object dibuat **dari object lain** | `Robot robot2 = robot1;` |
| 2 | Parameternya **harus** `const Robot &other` (reference) | `Robot(const Robot &other)` |
| 3 | Bukan `Robot(Robot other)` — sebab itu menyebabkan **rekursi** | `Robot(Robot other)` ❌ |
| 4 | Menyalin seluruh data member satu per satu | `name_(other.name_)` |

## Kode — `copy_constructor.cpp`

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

## Visualisasi

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

Object baru dibuat.
Seluruh isi robot1 disalin ke robot2.
```

## Kenapa parameter `const Robot &other`?

Perhatikan tanda tangan:

```cpp
Robot(const Robot &other);   // ✅ benar
```

Bukan:

```cpp
Robot(Robot other);          // ❌ SALAH!
```

**Mengapa?**

Jika ditulis `Robot(Robot other)`, maka untuk memanggil Copy Constructor, compiler harus **menyalin object dulu**. Menyalin object berarti **memanggil Copy Constructor lagi**, yang kemudian harus menyalin object lagi, dan seterusnya — terjadi **rekursi tak berujung**.

Karena itu parameter **wajib reference**. Dan karena object sumber tidak boleh berubah, digunakan `const`.

Ini adalah salah satu contoh penggunaan `const reference` yang **paling penting di seluruh C++**.

## Perbedaan Constructor Biasa vs Copy Constructor

| Constructor | Copy Constructor |
|-------------|------------------|
| `Robot(const std::string &name)` | `Robot(const Robot &other)` |
| Menerima **string** sebagai sumber | Menerima **object lain** sebagai sumber |
| Menginisialisasi dari nilai baru | Menyalin dari object yang sudah ada |
| `Robot robot1("NUIN");` | `Robot robot2 = robot1;` |

## Hubungan dengan ROS 2

Di ROS 2 Anda akan sering melihat pola seperti:

```cpp
Robot(const Robot &) = delete;
```

atau

```cpp
Node(const Node &) = delete;
```

**Mengapa?**

Karena banyak object ROS 2 tidak boleh dicopy sembarangan — misalnya publisher, subscriber, mutex, thread, socket, dan resource sistem. Dengan memahami Copy Constructor sekarang, saat melihat kode ROS 2 seperti itu Anda akan langsung tahu maksudnya.

## Command Line

```bash
g++ copy_constructor.cpp -o copy_constructor && ./copy_constructor
```

## Target Pembelajaran

Di akhir bab ini, Anda diharapkan memahami:

- ✅ Apa itu Copy Constructor
- ✅ Kapan Copy Constructor dipanggil
- ✅ Mengapa parameternya bertipe `const Robot &other`
- ✅ Perbedaan constructor biasa dan Copy Constructor
- ✅ Mengapa Copy Constructor sangat penting dalam desain object C++ modern

## Langkah Selanjutnya

Setelah bab ini, langkah paling alami adalah **Copy Assignment Operator** (`operator=`). Di situlah Anda akan memahami perbedaan antara:

```cpp
Robot robot2 = robot1;   // Copy Constructor
```

```cpp
Robot robot2;
robot2 = robot1;         // Copy Assignment Operator
```

Perbedaannya tampak kecil di kode, tetapi secara internal keduanya adalah mekanisme yang berbeda dan merupakan fondasi penting sebelum mempelajari **move semantics** serta **smart pointer**.

## Latihan

1. Hapus Copy Constructor dari class — compile. Apakah program tetap jalan? (Compiler membuat implicit copy constructor).
2. Ganti `Robot(const Robot &other)` menjadi `Robot(Robot other)` — compile dan lihat error.
3. Tambah `std::cout << "Address other: " << &other << '\n';` di dalam Copy Constructor — apakah alamat `other` sama dengan `robot1`?
4. Buat fungsi `void printRobot(Robot r)` — panggil dengan `robot1`. Constructor mana yang dipanggil?
