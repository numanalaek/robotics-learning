#include <iostream>

int main()
{
    constexpr int SENSOR_COUNT = 8;

    int sensors[SENSOR_COUNT] =
        {
            120, 45, 80, 30,
            65, 90, 20, 55};

    for (int sensor : sensors)
    {
        std::cout << sensor << " cm\n";
    }

    return 0;
}
