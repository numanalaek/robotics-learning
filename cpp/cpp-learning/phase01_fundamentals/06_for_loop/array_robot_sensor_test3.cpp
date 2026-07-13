#include <iostream>

int main()
{
    int ultrasonic[5] = {120, 98, 150, 110, 95};

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Sensor "
                  << i
                  << " = "
                  << ultrasonic[i]
                  << " cm\n";
    }

    return 0;
}
