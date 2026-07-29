// ============================================================
// destructor.cpp — Destructor & object lifetime
// ============================================================
// Compile & run:
//   g++ destructor.cpp -o destructor && ./destructor
// ============================================================

#include <iostream>

// --- Class dengan constructor & destructor -------------------

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

// --- main: membuktikan lifetime object -----------------------
// Output:
//   Constructor    ← robot1
//   Constructor    ← robot2
//   Destructor     ← robot2 (keluar scope blok { })
//   Constructor    ← robot3
//   Destructor     ← robot3 (akhir main)
//   Destructor     ← robot1 (akhir main)

int main()
{
    Robot robot1;        // Constructor → robot1 hidup di scope main()

    {                    // buka scope blok
        Robot robot2;    // Constructor → robot2 hidup di dalam blok
    }                    // keluar scope → Destructor robot2

    Robot robot3;        // Constructor → robot3 hidup di scope main()
}                        // akhir main → Destructor robot3, lalu robot1
