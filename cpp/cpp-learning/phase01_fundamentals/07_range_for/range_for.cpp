// ============================================================
// Program 07a: Range-based For Loop - Battery Cell Monitor
// Deskripsi : Memeriksa 6 sel baterai dengan range-based for,
//             menghitung min, max, rata-rata, dan sel lemah.
// Konsep    : - for (const double &cell : cells)
//             - Iterasi otomatis tanpa indeks
//             - Lebih sederhana dari for loop biasa
//             - Cocok untuk membaca seluruh elemen array
// ============================================================

#include <iostream>
#include <iterator>

int main()
{
    // Tegangan 6 sel baterai (dalam Volt)
    double cells[] =
        {
            3.21, 3.19, 3.24,
            3.18, 3.22, 3.20};

    constexpr double LOW_CELL_LIMIT = 3.20;

    double min = cells[0];
    double max = cells[0];
    double sum = 0;
    bool has_low_cell = false;

    // Range-based for: untuk setiap elemen cell di dalam array cells
    // const double &cell = reference read-only (tidak copy, tidak bisa ubah)
    for (const double &cell : cells)
    {
        if (cell < min)
            min = cell;
        if (cell > max)
            max = cell;
        sum += cell;
        if (cell < LOW_CELL_LIMIT)
            has_low_cell = true;
    }

    // std::size(cells) menghitung jumlah elemen array secara otomatis
    double avg = sum / std::size(cells);

    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << "Min: " << min << " V\n";
    std::cout << "Max: " << max << " V\n";
    std::cout << "Avg: " << avg << " V\n";

    if (has_low_cell)
        std::cout << "LOW CELL\n";
    else
        std::cout << "BATTERY NORMAL\n";

    return 0;
}
