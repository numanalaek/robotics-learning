#include <iostream>

// ============================================================
// ENCAPSULATION — menyembunyikan data member dari akses langsung
// ============================================================

class Robot
{
    // private: data member hanya bisa diakses dari dalam class
private:
    int battery;

    // public: member function sebagai jembatan ke dunia luar
public:
    // Constructor — menginisialisasi battery dengan nilai awal 100
    Robot()
        : battery(100)
    {
    }

    // const member function — tidak mengubah data member
    void printStatus() const
    {
        std::cout
            << "Battery : "
            << battery
            << "%\n";
    }
};

int main()
{
    // Membuat object Robot — constructor akan memanggil Robot()
    Robot robot;

    // Jika baris berikut di-uncomment, akan error:
    //   'int Robot::battery' is private within this context
    // karena battery bersifat private dan tidak bisa diakses dari luar class.
    // robot.battery = 50;

    // Satu-satunya cara membaca battery adalah lewat public member function
    robot.printStatus();

    return 0;
}
