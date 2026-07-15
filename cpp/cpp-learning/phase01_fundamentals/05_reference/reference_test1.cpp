// ============================================================
// Program 05e: Perbandingan Pass by Value vs Pass by Reference
// Deskripsi : Membandingkan langsung perbedaan antara
//             pass by value dan pass by reference.
// Konsep    : - Pass by value: copy, nilai asli TIDAK berubah
//             - Pass by reference: alias, nilai asli BERUBAH
//             - Alamat memori berbeda (value) vs sama (reference)
//             - Dengan reference, fungsi memodifikasi variabel asli
// ============================================================

#include <iostream>

// Pass by value: battery adalah COPY, alamat berbeda
void decreaseByValue(int battery)
{
    std::cout << "  [decreaseByValue] &battery (dalam fungsi) = " << &battery << "\n";
    battery -= 10;
    std::cout << "  [decreaseByValue] battery di dalam fungsi = " << battery << "\n";
}

// Pass by reference: battery adalah REFERENCE, alamat SAMA
void decreaseByReference(int &battery)
{
    std::cout << "  [decreaseByReference] &battery (dalam fungsi) = " << &battery << "\n";
    battery -= 10;
    std::cout << "  [decreaseByReference] battery di dalam fungsi = " << battery << "\n";
}

int main()
{
    std::cout << "=== Perbedaan Pass by Value vs Pass by Reference ===\n\n";

    // ----- PASS BY VALUE -----
    int battery1 = 100;
    std::cout << "1) Pass by Value:\n";
    std::cout << "  &battery1 (di main) = " << &battery1 << "\n";
    std::cout << "  Sebelum panggil fungsi: battery = " << battery1 << "\n";
    decreaseByValue(battery1);
    std::cout << "  Setelah panggil fungsi: battery = " << battery1 << "\n";
    std::cout << "  -> Nilai TIDAK berubah (alamat berbeda -> copy).\n\n";

    // ----- PASS BY REFERENCE -----
    int battery2 = 100;
    std::cout << "2) Pass by Reference:\n";
    std::cout << "  &battery2 (di main) = " << &battery2 << "\n";
    std::cout << "  Sebelum panggil fungsi: battery = " << battery2 << "\n";
    decreaseByReference(battery2);
    std::cout << "  Setelah panggil fungsi: battery = " << battery2 << "\n";
    std::cout << "  -> Nilai BERUBAH (alamat sama -> variabel asli).\n";

    return 0;
}
