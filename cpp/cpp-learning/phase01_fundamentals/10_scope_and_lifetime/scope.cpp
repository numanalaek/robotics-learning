#include <iostream>

int robot_id = 1;

int main()
{
    int battery = 100;

    std::cout << "Robot ID : " << robot_id << '\n';
    std::cout << "Battery  : " << battery << '\n';

    {
        int sensor_distance = 45;

        std::cout << "Sensor   : "
                  << sensor_distance
                  << " cm\n";
    }

    // Coba uncomment baris berikut untuk melihat error:
    // std::cout << sensor_distance << '\n';

    return 0;
}
