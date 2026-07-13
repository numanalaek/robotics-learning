#include <iostream>

int main()
{
    int sensors[] = {120, 45, 80, 30, 65, 90, 20, 55};

    for (const int &sensor : sensors)
    {
        std::cout << sensor << '\n';
    }

    return 0;
}

// 1. int sensor — copy, aman tapi boros untuk objek besar
// 2. int &sensor — reference, bisa ubah array asli
// 3. const int &sensor — const reference, baca saja tanpa copy (paling efisien & aman)
