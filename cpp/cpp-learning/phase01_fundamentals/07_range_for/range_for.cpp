// ============================================================
// Program 07a: Range-based For Loop - Battery Cell Monitor
// Description: Checks 6 battery cells with range-based for,
//             calculates min, max, average, and weak cell.
// Concepts  : - for (const double &cell : cells)
//             - Automatic iteration without index
//             - Simpler than regular for loop
//             - Suitable for reading all array elements
// ============================================================

#include <iostream>
#include <iterator>

int main()
{
    // Voltage of 6 battery cells (in Volts)
    double cells[] =
        {
            3.21, 3.19, 3.24,
            3.18, 3.22, 3.20};

    constexpr double LOW_CELL_LIMIT = 3.20;

    double min = cells[0];
    double max = cells[0];
    double sum = 0;
    bool has_low_cell = false;

    // Range-based for: for each element cell in the cells array
    // const double &cell = read-only reference (no copy, cannot modify)
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

    // std::size(cells) calculates the number of array elements automatically
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
