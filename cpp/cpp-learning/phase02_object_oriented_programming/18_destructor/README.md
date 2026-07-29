# 18. Destructor dalam C++

## Empat Hal Penting tentang Destructor

| # | Aturan | Contoh |
|---|--------|--------|
| 1 | Dipanggil **otomatis** saat objek **keluar dari scope** | `{ Robot r; }` → `~Robot()` jalan saat `}` |
| 2 | Nama **sama persis** dengan nama class, diawali `~` | `~Robot()` |
| 3 | **Tidak punya return type** dan **tidak boleh overload** | `~Robot();` ✅ | `~Robot(int);` ❌ |
| 4 | **Membersihkan resource** (memory, file, mutex, dll) | `delete[] data;` di dalam `~Robot()` |

## Kode

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

### Penjelasan urutan output:

| Langkah | Kode | Output | Keterangan |
|---------|------|--------|------------|
| 1 | `Robot robot1;` | `Constructor` | robot1 dibuat di scope `main()` |
| 2 | `Robot robot2;` | `Constructor` | robot2 dibuat di scope blok `{ }` |
| 3 | `}` | `Destructor` | **robot2 dihancurkan** saat keluar scope blok |
| 4 | `Robot robot3;` | `Constructor` | robot3 dibuat di scope `main()` |
| 5 | `return 0;` | `Destructor` | robot3 dihancurkan (urutan terbalik: robot3 dulu) |
| 6 | `return 0;` | `Destructor` | robot1 dihancurkan |

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

Destructor membuktikan aturan fundamental **lifetime** di C++:

```
{                            // ← masuk scope
    Robot r;                 // Constructor → r "hidup"
    // r bisa digunakan di sini
}                            // ← keluar scope → Destructor → r "mati"
```

Variabel lokal hidup dari titik deklarasi hingga akhir scope `{ }`-nya. Destructor **pasti dipanggil**, bahkan jika ada `return`, `break`, atau exception — inilah jaminan RAII.

## Analogi

Destructor seperti **akta kematian** — saat objek "mati", semua resource-anya dibereskan.

| Objek | Lahir | Mati |
|-------|-------|------|
| `Robot robot1` | `Constructor` | `Destructor` (akhir main) |
| `Robot robot2` | `Constructor` | `Destructor` (akhir scope `{ }`) |
| `Robot robot3` | `Constructor` | `Destructor` (akhir main) |

Tanpa destructor → resource bocor (memory leak, file tidak ditutup, mutex tidak di-unlock).

## Latihan

1. Hapus destructor → compile → tidak ada error (compiler bikin default). Apakah output berubah?
2. Tambahkan `Robot robot4;` di akhir scope `main()` — prediksi output sebelum menjalankan.
3. Bungkus `robot3` dalam scope blok sendiri → apa yang terjadi pada urutan output?
4. Tambahkan `static Robot robot_static;` — kapan destructor static dipanggil?
