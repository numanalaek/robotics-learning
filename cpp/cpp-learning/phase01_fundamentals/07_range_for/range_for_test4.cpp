#include <iostream>

int main()
{
    int sensors[] = {120, 45, 80, 30, 65, 90, 20, 55};

    std::cout << "Before:\n";
    for (int sensor : sensors)
    {
        std::cout << sensor << ' ';
    }
    std::cout << '\n';

    for (int &sensor : sensors)
    {
        sensor = 0;
    }

    std::cout << "After:\n";
    for (int sensor : sensors)
    {
        std::cout << sensor << ' ';
    }
    std::cout << '\n';

    std::cout << "Array berubah karena sensor adalah reference.\n";

    return 0;
}
