#include <iostream>
#include <string>

void printName(std::string name) // pass by value
{
    std::cout << "Alamat di fungsi : " << &name << '\n';
    std::cout << "Isi di fungsi    : " << name << '\n';
    name = "MODIFIED";
    std::cout << "Setelah diubah   : " << name << '\n';
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
