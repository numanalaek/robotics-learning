#include <iostream>

int main()
{
    int ultrasonic[7] = {120, 98, 150, 110, 95, 70, 130};

    for (int i = 0; i < 7; i++)
    {
        if (ultrasonic[i] < 100)
        {
            std::cout << "Sensor "
                      << i
                      << " : OBSTACLE\n";
        }
        else
        {
            std::cout << "Sensor "
                      << i
                      << " : CLEAR\n";
        }
    }

    return 0;
}
