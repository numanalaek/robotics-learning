// import library iostream untuk input/output standar (cin, cout)
#include <iostream>
// import library string untuk tipe data std::string
#include <string>

// mendefinisikan kelas Robot
class Robot
{
// bagian private: hanya dapat diakses dari dalam kelas
private:
    int battery;          // menyimpan persentase baterai (0-100)
    double voltage;       // menyimpan tegangan dalam volt
    std::string mode;     // menyimpan mode operasi robot

// bagian public: dapat diakses dari luar kelas
public:
    // --- PARAMETERIZED CONSTRUCTOR ---
    // constructor dengan 3 parameter untuk menginisialisasi data member
    Robot(int battery_,
          double voltage_,
          const std::string &mode_)
        // initializer list: cara efisien menginisialisasi data member
        : battery(battery_),
          voltage(voltage_),
          mode(mode_)
    {
        // body constructor kosong karena inisialisasi sudah dilakukan
        // oleh initializer list di atas
    }

    // method untuk mencetak status robot
    // const => method ini tidak mengubah data member
    void printStatus() const
    {
        // menampilkan nilai battery, voltage, dan mode ke layar
        std::cout
            << "Battery : " << battery << "%\n"
            << "Voltage : " << voltage << " V\n"
            << "Mode    : " << mode << "\n";
    }
};

// fungsi utama program
int main()
{
    // membuat objek Robot dengan parameterized constructor
    // nilai 85, 24.3, "AUTO" dikirim ke constructor sebagai argumen
    Robot robot(
        85,       // battery = 85%
        24.3,     // voltage = 24.3 V
        "AUTO");  // mode = "AUTO"

    // memanggil method printStatus() untuk menampilkan data robot
    robot.printStatus();

    return 0;
}
