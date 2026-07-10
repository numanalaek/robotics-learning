#include <iostream>

int main()
{
    int battery = 100;
    double voltage = 24.6;
    char command = 'W';

    std::cout << "battery : " << battery << '\n';
    std::cout << "voltage : " << voltage << '\n';
    std::cout << "command : " << command << '\n';

    std::cout << "\nAddress\n";

    std::cout << "battery : " << &battery << '\n';
    std::cout << "voltage : " << &voltage << '\n';
    std::cout << "command : " << static_cast<void *>(&command) << '\n';

    return 0;
}
