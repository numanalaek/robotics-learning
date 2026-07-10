#include <iostream>

int main()
{
    int battery = 100;

    std::cout << "battery : " << battery << '\n';
    std::cout << "&battery : " << &battery << '\n';

    int *ptr = &battery;

    std::cout << "ptr : " << ptr << '\n';
    std::cout << "*ptr : " << *ptr << '\n';

    *ptr = 50;

    std::cout << battery << '\n';

    return 0;
}
