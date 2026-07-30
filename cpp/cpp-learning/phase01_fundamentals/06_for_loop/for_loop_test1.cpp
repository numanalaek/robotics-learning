// ============================================================
// Program 06b: Basic For Loop
// Description: Simplest for loop - prints robot steps
//             5 times.
// Concepts  : - for (initialization; condition; increment)
//             - int i = 0: start from 0
//             - i < 5: while i is less than 5
//             - i++: each iteration i increases by 1
// ============================================================

#include <iostream>

int main()
{
    // Loop from i=0 to i<5 (0,1,2,3,4 = 5 iterations)
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Robot Move Step : " << i << '\n';
    }

    return 0;
}
