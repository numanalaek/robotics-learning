// ============================================================
// Program 07f: Range-based For - const Reference
// Deskripsi : Menggunakan const reference untuk membaca array
//             tanpa copy dan tanpa bisa mengubah data asli.
// Konsep    : - const int &sensor: baca saja, tidak bisa ubah
//             - Paling efisien dan aman untuk iterasi baca
//             - Tiga varian:
//               1. int sensor       -> copy (boros untuk objek besar)
//               2. int &sensor      -> reference (bisa ubah asli)
//               3. const int &sensor -> const reference (baca saja)
// ============================================================

#include <iostream>

int main()
{
    int sensors[] = {120, 45, 80, 30, 65, 90, 20, 55};

    // const reference: efisien (tanpa copy) dan aman (tidak bisa ubah)
    for (const int &sensor : sensors)
    {
        std::cout << sensor << '\n';
    }

    return 0;
}

// 1. int sensor — copy, aman tapi boros untuk objek besar
// 2. int &sensor — reference, bisa ubah array asli
// 3. const int &sensor — const reference, baca saja tanpa copy (paling efisien & aman)
