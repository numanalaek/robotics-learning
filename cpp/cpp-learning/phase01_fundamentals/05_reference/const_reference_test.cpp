// membuktikan bahwa reference tidak bisa diubah nilainya
// sehingga tidak bisa mengubah nilai dari variabel yang direferensikan
// dan error akan muncul saat compile
#include <iostream>
#include <string>

void printName(const std::string &name)
{
    name = "TEST"; // error: assignment of read-only reference 'name'
}

int main()
{
    std::string robot = "NUIN-AMR-01";
    printName(robot);
    return 0;
}
