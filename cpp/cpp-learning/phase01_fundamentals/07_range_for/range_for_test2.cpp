#include <iostream>

int main()
{
    int sensors[] = {120, 45, 80, 30, 65, 90, 20, 55};

    int sum = 0;

    for (int sensor : sensors)
    {
        sum += sensor;
    }

    double average =
        static_cast<double>(sum) / 8;

    std::cout << "Average = "
              << average
              << '\n';
}
