#include <iostream>

int main()
{
    int battery = 100;

    std::cout << "Outside block: "
              << battery
              << '\n';

    {
        int voltage = 24;

        std::cout << "Inside block:\n";
        std::cout << "Battery : " << battery << '\n';
        std::cout << "Voltage : " << voltage << '\n';
    }

    std::cout << "Outside block again:\n";
    std::cout << "Battery : " << battery << '\n';

    // std::cout << voltage << '\n'; // ERROR

    return 0;
}
