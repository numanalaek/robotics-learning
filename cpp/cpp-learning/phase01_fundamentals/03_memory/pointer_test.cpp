#include <iostream>

int main()
{
    int battery = 100;

    int *ptr = &battery;

    std::cout << "battery : " << battery << '\n';
    std::cout << "ptr : " << ptr << '\n';
    std::cout << "*ptr : " << *ptr << '\n';
    std::cout << "&battery : " << &battery << '\n';

    std::cout << "\nChange the value of battery using pointer\n";
    *ptr = 50;

    std::cout << "battery : " << battery << '\n';
    std::cout << "ptr : " << ptr << '\n';
    std::cout << "*ptr : " << *ptr << '\n';
    std::cout << "&battery : " << &battery << '\n';

    std::cout << "\nChange the value of battery using pointer\n";
    *ptr = 80;

    std::cout << "battery : " << battery << '\n';
    std::cout << "ptr : " << ptr << '\n';
    std::cout << "*ptr : " << *ptr << '\n';
    std::cout << "&battery : " << &battery << '\n';
    return 0;
}
