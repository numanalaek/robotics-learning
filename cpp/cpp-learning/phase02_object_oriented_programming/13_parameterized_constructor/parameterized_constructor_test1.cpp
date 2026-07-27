// import library iostream untuk input/output standar (cin, cout)
#include <iostream>
// import library string untuk tipe data std::string
#include <string>

// mendefinisikan kelas Robot
class Robot
{
    // bagian private: hanya dapat diakses dari dalam kelas
private:
    int id;           // menyimpan ID unik robot
    int battery;      // menyimpan persentase baterai (0-100)
    std::string mode; // menyimpan mode operasi robot

    // bagian public: dapat diakses dari luar kelas
public:
    // --- PARAMETERIZED CONSTRUCTOR ---
    // nama parameter menggunakan prefix "robot_" untuk membedakan
    // dari nama data member (meskipun tidak wajib, bisa berbeda)
    Robot(
        int robot_id,
        int robot_battery,
        const std::string &robot_mode)
        // initializer list: menginisialisasi data member dengan nilai parameter
        : id(robot_id),
          battery(robot_battery),
          mode(robot_mode)
    {
        // body constructor kosong karena inisialisasi sudah
        // ditangani oleh initializer list
    }

    // method untuk menampilkan status robot dalam satu baris
    // const => method ini tidak mengubah data member
    void printStatus() const
    {
        // menampilkan id, battery, dan mode dengan format terstruktur
        std::cout
            << "Robot " << id
            << " | Battery "
            << battery
            << "% | "
            << mode
            << '\n';
    }
};

// fungsi utama program
int main()
{
    // --- MEMBUAT MULTIPLE OBJECT DENGAN PARAMETERIZED CONSTRUCTOR ---
    // setiap objek dapat memiliki nilai inisialisasi yang berbeda

    // membuat robot pertama dengan ID 1, baterai 95%, mode AUTO
    Robot robot1(
        1,
        95,
        "AUTO");

    // membuat robot kedua dengan ID 2, baterai 60%, mode MANUAL
    Robot robot2(
        2,
        60,
        "MANUAL");

    // memanggil method printStatus() untuk masing-masing robot
    robot1.printStatus();
    robot2.printStatus();

    return 0;
}
