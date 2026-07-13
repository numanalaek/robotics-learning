#include <iostream>
#include <iterator>

int main()
{
    double cells[] =
        {
            3.21,
            3.19,
            3.24,
            3.18,
            3.22,
            3.20};

    constexpr double LOW_CELL_LIMIT = 3.20;

    double min = cells[0];
    double max = cells[0];
    double sum = 0;
    bool has_low_cell = false;

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
