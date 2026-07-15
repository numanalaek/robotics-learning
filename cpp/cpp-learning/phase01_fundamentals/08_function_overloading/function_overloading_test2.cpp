// ============================================================
// Program 08c: Overloading - Tipe Parameter Berbeda
// Deskripsi : Overloading dengan tipe parameter berbeda
//             (int vs double). Compiler memilih berdasarkan
//             tipe argumen yang diberikan.
// Konsep    : - setSpeed(int)    : dipanggil jika argumen integer
//             - setSpeed(double) : dipanggil jika argumen desimal
//             - Tipe parameter bisa int, double, float, dll.
// ============================================================

#include <iostream>

// Versi untuk kecepatan integer
void setSpeed(int speed)
{
    std::cout << "Speed = " << speed << " m/s (integer)\n";
}

// Versi untuk kecepatan desimal
void setSpeed(double speed)
{
    std::cout << "Speed = " << speed << " m/s (double)\n";
}

int main()
{
    setSpeed(1);      // 1 adalah int -> panggil versi int
    setSpeed(1.25);   // 1.25 adalah double -> panggil versi double
}
