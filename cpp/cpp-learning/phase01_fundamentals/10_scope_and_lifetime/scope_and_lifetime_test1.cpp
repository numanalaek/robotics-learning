#include <iostream>

int global_value = 100;

void testFunction()
{
    int function_value = 200;

    std::cout << "Inside function:\n";
    std::cout << "global_value   : " << global_value << '\n';
    std::cout << "function_value : " << function_value << '\n';
}

int main()
{
    int main_value = 300;

    std::cout << "Inside main:\n";
    std::cout << "global_value : " << global_value << '\n';
    std::cout << "main_value   : " << main_value << '\n';

    testFunction();

    return 0;
}
