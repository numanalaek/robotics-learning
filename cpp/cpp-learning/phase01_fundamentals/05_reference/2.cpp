// contoh penggunaan reference pada parameter fungsi
#include <iostream>
#include <string>

void printName(const std::string &name)
{
    std::cout << "Alamat di fungsi : "
              << &name << '\n';

    std::cout << "Robot : "
              << name << '\n';
}

int main()
{
    std::string robot = "NUIN-AMR-01";

    std::cout << "Alamat di main   : "
              << &robot << '\n';

    printName(robot);

    return 0;
}
