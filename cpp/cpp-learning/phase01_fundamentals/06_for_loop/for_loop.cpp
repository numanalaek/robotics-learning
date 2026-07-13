#include <iostream>

int main()
{
    constexpr int SENSOR_COUNT = 8;

    int sensors[SENSOR_COUNT] =
        {
            120, 45, 80, 30,
            65, 90, 20, 55};

    int sensor_sum = 0;
    int min = sensors[0];
    int max = sensors[0];
    int warning_count = 0;

    for (int i = 0; i < SENSOR_COUNT; ++i)
    {
        std::cout
            << "Sensor "
            << i
            << " = "
            << sensors[i]
            << " cm";

        if (sensors[i] < 50)
        {
            std::cout << "  <-- WARNING";
            ++warning_count;
        }

        std::cout << '\n';

        sensor_sum += sensors[i];

        if (sensors[i] < min)
            min = sensors[i];

        if (sensors[i] > max)
            max = sensors[i];
    }

    int safe_count = SENSOR_COUNT - warning_count;
    double average = static_cast<double>(sensor_sum) / SENSOR_COUNT;

    std::cout << "\n--- Statistics ---\n";
    std::cout << "Minimum : " << min << " cm\n";
    std::cout << "Maximum : " << max << " cm\n";
    std::cout << "Average : " << average << " cm\n";

    std::cout << "\nWarning : " << warning_count << "\n";
    std::cout << "Safe    : " << safe_count << "\n";

    std::cout << "\nRobot Status : ";
    if (warning_count == 0)
        std::cout << "SAFE\n";
    else if (warning_count <= 2)
        std::cout << "CAUTION\n";
    else
        std::cout << "EMERGENCY\n";

    return 0;
}
