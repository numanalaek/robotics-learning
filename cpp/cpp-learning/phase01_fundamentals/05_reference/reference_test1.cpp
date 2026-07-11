#include <iostream>

void decreaseByValue(int battery)
{
    std::cout << "  [decreaseByValue] &battery (dalam fungsi) = " << &battery << "\n";
    battery -= 10;
    std::cout << "  [decreaseByValue] battery di dalam fungsi = " << battery << "\n";
}

void decreaseByReference(int &battery)
{
    std::cout << "  [decreaseByReference] &battery (dalam fungsi) = " << &battery << "\n";
    battery -= 10;
    std::cout << "  [decreaseByReference] battery di dalam fungsi = " << battery << "\n";
}

int main()
{
    std::cout << "=== Perbedaan Pass by Value vs Pass by Reference ===\n\n";

    int battery1 = 100;
    std::cout << "1) Pass by Value:\n";
    std::cout << "  &battery1 (di main) = " << &battery1 << "\n";
    std::cout << "  Sebelum panggil fungsi: battery = " << battery1 << "\n";
    decreaseByValue(battery1);
    std::cout << "  Setelah panggil fungsi: battery = " << battery1 << "\n";
    std::cout << "  -> Nilai TIDAK berubah (alamat berbeda -> copy).\n\n";

    int battery2 = 100;
    std::cout << "2) Pass by Reference:\n";
    std::cout << "  &battery2 (di main) = " << &battery2 << "\n";
    std::cout << "  Sebelum panggil fungsi: battery = " << battery2 << "\n";
    decreaseByReference(battery2);
    std::cout << "  Setelah panggil fungsi: battery = " << battery2 << "\n";
    std::cout << "  -> Nilai BERUBAH (alamat sama -> variabel asli).\n";

    return 0;
}
