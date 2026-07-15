// ============================================================
// Program 09a: Default Parameters
// Deskripsi : Fungsi dengan parameter default sehingga bisa
//             dipanggil dengan jumlah argumen yang berbeda.
// Konsep    : - Parameter default diberikan di deklarasi/definisi
//             - robotStatus()           -> semua pakai default
//             - robotStatus(80)         -> battery=80, sisanya default
//             - robotStatus(80, 23.5)   -> battery & voltage diisi
//             - robotStatus(80,23.5,true) -> semua diisi
//             - Default hanya bisa di parameter paling kanan
// ============================================================

#include <iomanip>
#include <iostream>

// Semua parameter punya nilai default
// Parameter dengan default harus di paling kanan
void robotStatus(
    int battery = 100,
    double voltage = 24.0,
    bool obstacle = false)
{
    std::cout << std::fixed << std::setprecision(1);

    std::cout
        << "Battery  : " << battery << "%\n"
        << "Voltage  : " << voltage << " V\n"
        << "Obstacle : "
        << (obstacle ? "YES" : "NO")
        << "\n\n";
}

int main()
{
    // Berbagai cara memanggil fungsi dengan default parameter
    robotStatus();                  // Semua default
    robotStatus(80);                // battery=80, voltage & obstacle default
    robotStatus(80, 23.5);          // battery=80, voltage=23.5
    robotStatus(80, 23.5, true);    // Semua diisi

    return 0;
}
