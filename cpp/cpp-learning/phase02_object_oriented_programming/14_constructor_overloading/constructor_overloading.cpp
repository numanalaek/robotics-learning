// ============================================================
// Program 1 — Constructor Overloading
// ============================================================
// Compile & run:
//   g++ constructor_overloading.cpp -o constructor_overloading
//   ./constructor_overloading
// ============================================================

#include <iostream>   // untuk std::cout
#include <string>     // untuk std::string

// ============================================================
// Class Robot — memiliki 4 constructor dengan parameter berbeda
// ============================================================
class Robot
{
private:
    int battery;          // member variable: level battery
    double voltage;       // member variable: voltage
    std::string mode;     // member variable: mode operasi

public:
    // --- Constructor 1: tanpa parameter ---
    // Digunakan saat: Robot robot1;
    // Semua nilai menggunakan default
    Robot()
        : battery(100),     // battery = 100%
          voltage(24.5),    // voltage = 24.5 V
          mode("READY")     // mode = READY
    {
    }

    // --- Constructor 2: 1 parameter (int) ---
    // Digunakan saat: Robot robot2(80);
    // battery diatur dari argumen, sisanya default
    Robot(int battery_)
        : battery(battery_),  // battery = nilai argumen
          voltage(24.5),      // voltage = default
          mode("READY")       // mode = default
    {
    }

    // --- Constructor 3: 2 parameter (int, double) ---
    // Digunakan saat: Robot robot3(75, 24.1);
    // battery & voltage diatur, mode default
    Robot(int battery_,
          double voltage_)
        : battery(battery_),   // battery = nilai argumen
          voltage(voltage_),   // voltage = nilai argumen
          mode("READY")        // mode = default
    {
    }

    // --- Constructor 4: 3 parameter (int, double, string) ---
    // Digunakan saat: Robot robot4(60, 23.8, "AUTO");
    // Semua member diatur dari argumen
    Robot(int battery_,
          double voltage_,
          const std::string &mode_)
        : battery(battery_),   // battery = nilai argumen
          voltage(voltage_),   // voltage = nilai argumen
          mode(mode_)          // mode = nilai argumen
    {
    }

    // Menampilkan status robot
    void printStatus() const
    {
        std::cout
            << "Battery : " << battery << "%\n"
            << "Voltage : " << voltage << " V\n"
            << "Mode    : " << mode << "\n\n";
    }
};

// ============================================================
// main() — membuktikan compiler memilih constructor yg tepat
// ============================================================
int main()
{
    // Membuat 4 object, masing-masing dengan constructor berbeda
    Robot robot1;                  // memanggil Robot()
    Robot robot2(80);              // memanggil Robot(int)
    Robot robot3(75, 24.1);        // memanggil Robot(int, double)
    Robot robot4(60, 23.8, "AUTO");// memanggil Robot(int, double, string)

    // Cetak status semua robot
    robot1.printStatus();
    robot2.printStatus();
    robot3.printStatus();
    robot4.printStatus();

    return 0;
}
// ============================================================
// OUTPUT:
// Battery : 100%
// Voltage : 24.5 V
// Mode    : READY
//
// Battery : 80%
// Voltage : 24.5 V
// Mode    : READY
//
// Battery : 75%
// Voltage : 24.1 V
// Mode    : READY
//
// Battery : 60%
// Voltage : 23.8 V
// Mode    : AUTO
// ============================================================
