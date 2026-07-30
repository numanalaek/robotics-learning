// ============================================================
// Program 03c: Pointer - Changing Values
// Description: Demonstrates how pointers are used to modify
//             variable values multiple times.
// Concepts  : - Pointer ptr always stores the same address
//             - *ptr = new_value changes the original variable's content
//             - battery, *ptr, and &battery show the relationship
//               between variable, pointer, and memory address
// ============================================================

#include <iostream>

int main()
{
    int battery = 100;

    // Pointer ptr points to battery's address
    int *ptr = &battery;

    // Display initial state
    std::cout << "battery : " << battery << '\n';
    std::cout << "ptr : " << ptr << '\n';
    std::cout << "*ptr : " << *ptr << '\n';
    std::cout << "&battery : " << &battery << '\n';

    // Change battery to 50 through pointer
    std::cout << "\nChange the value of battery using pointer\n";
    *ptr = 50;

    std::cout << "battery : " << battery << '\n';
    std::cout << "ptr : " << ptr << '\n';
    std::cout << "*ptr : " << *ptr << '\n';
    std::cout << "&battery : " << &battery << '\n';

    // Change battery to 80 through pointer
    std::cout << "\nChange the value of battery using pointer\n";
    *ptr = 80;

    std::cout << "battery : " << battery << '\n';
    std::cout << "ptr : " << ptr << '\n';
    std::cout << "*ptr : " << *ptr << '\n';
    std::cout << "&battery : " << &battery << '\n';

    return 0;
}
