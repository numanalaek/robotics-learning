// ============================================================
// Program 03b: Basic Pointer
// Description: Introduces the concept of pointers - variables
//             that store the memory address of other variables.
// Concepts  : - Pointer: a variable that holds an address, not a value
//             - int *ptr = &battery: ptr stores battery's address
//             - *ptr (dereference): accesses the value at that address
//             - With pointers, we can change the original variable's
//               value indirectly
// ============================================================

#include <iostream>

int main()
{
    int battery = 100;

    // Display battery's value and address
    std::cout << "battery : " << battery << '\n';
    std::cout << "&battery : " << &battery << '\n';

    // Declare a pointer that points to battery's address
    int *ptr = &battery;

    // ptr holds the address, *ptr holds the value at that address
    std::cout << "ptr : " << ptr << '\n';
    std::cout << "*ptr : " << *ptr << '\n';

    // Change battery's value through the pointer (dereference)
    *ptr = 50;

    // Battery's value changes because *ptr accesses the same memory
    std::cout << battery << '\n';

    return 0;
}
