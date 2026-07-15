// ============================================================
// Program 05h: Error Const Reference (Demo)
// Deskripsi : Program ini sengaja dibuat ERROR untuk menunjukkan
//             bahwa const reference TIDAK BISA diubah nilainya.
// Konsep    : - const reference bersifat read-only
//             - Mencoba mengubahnya akan menyebabkan error
//               compile: "assignment of read-only reference"
//             - Ini adalah fitur keamanan C++
// ============================================================

#include <iostream>
#include <string>

void printName(const std::string &name)
{
    name = "TEST"; // ERROR: assignment of read-only reference 'name'
}

int main()
{
    std::string robot = "NUIN-AMR-01";
    printName(robot);
    return 0;
}
