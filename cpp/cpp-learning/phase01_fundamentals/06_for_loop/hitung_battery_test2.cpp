#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    int battery = 100;

    for (int i = 0; i < 100; i++)
    {
        battery--;
        std::cout << "Move " << i + 1
                  << " Battery = "
                  << battery << "%\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
