// ============================================================
// Program 10b: Scope — Global vs Function vs Main
// Deskripsi : Membandingkan akses variabel dari scope berbeda.
//             global_value bisa diakses dari main dan fungsi.
//             function_value hanya di dalam testFunction().
//             main_value hanya di dalam main().
// Konsep    : - Global scope bisa diakses dari fungsi mana pun
//             - Local scope terbatas pada fungsi tempat variabel
//               dideklarasikan
//             - main() dan testFunction() punya local scope
//               masing-masing yang tidak saling terlihat
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
