// ============================================================
// Program 06c: For Loop - Battery Simulation
// Description: Simulates robot battery decreasing each step
//             with a 1 second delay.
// Concepts  : - for loop from 0 to 99 (100 iterations)
//             - Decrement battery each step
//             - std::this_thread::sleep_for for time delay
//             - #include <thread> and <chrono> for timing
// ============================================================

#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    int battery = 100;

    // Loop 100 times (i = 0..99), each step battery decreases by 1
    for (int i = 0; i < 100; i++)
    {
        battery--;
        std::cout << "Move " << i + 1
                  << " Battery = "
                  << battery << "%\n";
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 1 second delay
    }

    return 0;
}
