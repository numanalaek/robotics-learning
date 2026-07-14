#include <iostream>

void move()
{
    std::cout << "Robot maju 1 langkah\n";
}

void move(int step)
{
    std::cout << "Robot maju "
              << step
              << " langkah\n";
}

int main()
{
    move();
    move(5);
}
