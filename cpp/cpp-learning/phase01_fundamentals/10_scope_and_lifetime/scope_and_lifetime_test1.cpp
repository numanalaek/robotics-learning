// ============================================================
// Program 10b: Scope — Global vs Function vs Main
// Description: Compares variable access from different scopes.
//             global_value can be accessed from main and functions.
//             function_value is only inside testFunction().
//             main_value is only inside main().
// Concepts  : - Global scope can be accessed from any function
//             - Local scope is limited to the function where the
//               variable is declared
//             - main() and testFunction() each have their own
//               local scope that are not visible to each other
// ============================================================

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
