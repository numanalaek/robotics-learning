// ============================================================
// destructor.cpp — Destructor & object lifetime
// ============================================================
// Compile & run:
//   g++ destructor.cpp -o destructor && ./destructor
// ============================================================

#include <iostream>

// --- Class with constructor & destructor -------------------

class Robot
{
public:
    Robot()
    {
        std::cout << "Constructor\n";
    }

    ~Robot()
    {
        std::cout << "Destructor\n";
    }
};

// --- main: proving object lifetime -----------------------
// Output:
//   Constructor    ← robot1
//   Constructor    ← robot2
//   Destructor     ← robot2 (exits block scope { })
//   Constructor    ← robot3
//   Destructor     ← robot3 (end of main)
//   Destructor     ← robot1 (end of main)

int main()
{
    Robot robot1;        // Constructor → robot1 lives in main() scope

    {                    // open block scope
        Robot robot2;    // Constructor → robot2 lives inside block
    }                    // exit scope → Destructor robot2

    Robot robot3;        // Constructor → robot3 lives in main() scope
}                        // end of main → Destructor robot3, then robot1
