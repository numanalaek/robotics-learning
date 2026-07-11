#include <iostream>
#include <string>

void printName(const std::string &name) // pass by const reference
{
    std::cout << "Alamat di fungsi : " << &name << '\n';
    std::cout << "Isi di fungsi    : " << name << '\n';

    // name = "MODIFIED";  // ERROR: const reference tidak bisa diubah
}

int main()
{
    std::string robot = "NUIN-AMR-01";

    std::cout << "Alamat di main   : " << &robot << '\n';
    std::cout << "Isi di main      : " << robot << '\n';

    printName(robot);

    std::cout << "Isi di main setelah fungsi : " << robot << '\n';

    return 0;
}
