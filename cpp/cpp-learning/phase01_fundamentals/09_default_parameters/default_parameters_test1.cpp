// ============================================================
// Program 09b: Default Parameter Sederhana
// Deskripsi : Fungsi printStatus dengan 1 default parameter.
// Konsep    : - printStatus()     -> battery=100 (default)
//             - printStatus(80)   -> battery=80
//             - Default memudahkan karena argumen bisa optional
// ============================================================

#include <iostream>

// battery memiliki nilai default 100
void printStatus(int battery = 100)
{
    std::cout << "Battery : " << battery << "%\n";
}

int main()
{
    printStatus();   // Pakai default: battery = 100
    printStatus(80); // Pakai argumen: battery = 80

    return 0;
}
