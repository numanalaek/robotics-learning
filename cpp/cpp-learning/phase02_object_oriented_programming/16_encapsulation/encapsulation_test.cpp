#include <iostream>

// ============================================================
// STRUCT COMPOSITION + ENCAPSULATION
// ============================================================
// struct: mengelompokkan data yang berkaitan menjadi satu kesatuan
// (mirip class, tapi default access-nya public)

// Battery — menyimpan status baterai robot
struct Battery
{
    int percent;    // persentase baterai (0–100)
    double voltage; // tegangan baterai dalam Volt
};

// Velocity — menyimpan kecepatan robot (linear & angular)
struct Velocity
{
    double linear;  // kecepatan linear (m/s)
    double angular; // kecepatan angular (rad/s)
};

// ============================================================
// CLASS ROBOT — menyembunyikan detail internal (encapsulation)
// ============================================================
// private:   data member — tidak bisa diakses langsung dari luar
// public:    member function — antarmuka ke dunia luar
// trailing underscore (_) pada nama member membedakannya dari
// parameter constructor (gaya ROS 2 / C++ modern)
class Robot
{
private:
    Battery battery_;    // data baterai (struct)
    Velocity velocity_;  // data kecepatan (struct)
    bool emergency_;     // status darurat

public:
    // Default constructor — semua data diisi nilai default
    Robot()
        : battery_{100, 12.5},    // battery 100%, 12.5V
          velocity_{0.0, 0.0},    // diam
          emergency_(false)       // tidak darurat
    {
    }

    // Parameterized constructor — menerima struct langsung (const reference)
    //   const Battery& battery  → parameter (tanpa _)
    //   battery_                → data member (dengan _)
    // Dengan konvensi _ , nama parameter bisa sama dengan nama member
    // tanpa menimbulkan ambiguity.
    Robot(const Battery &battery, const Velocity &velocity, bool emergency)
        : battery_(battery),     // copy dari parameter ke member
          velocity_(velocity),
          emergency_(emergency)
    {
    }

    // const member function — tidak mengubah data member
    void printStatus() const
    {
        // Akses data member lewat dot operator (.)
        std::cout
            << "Battery : " << battery_.percent << "% @ " << battery_.voltage << " V\n"
            << "Velocity: " << velocity_.linear << " m/s linear, " << velocity_.angular << " rad/s angular\n"
            << "Emergency: " << (emergency_ ? "ACTIVE" : "NONE") << "\n";
    }
};

// ============================================================
// MAIN — entry point program
// ============================================================
int main()
{
    // Membuat object Robot menggunakan parameterized constructor.
    // Aggregate initialization {} membuat temporary Battery dan Velocity
    //   {100, 24.5}  → Battery{percent=100, voltage=24.5}
    //   {0.0, 0.0}   → Velocity{linear=0.0, angular=0.0}
    // false          → emergency=false
    // Robot 1: AGV 24V, diam
    Robot robot1({100, 24.5}, {0.0, 0.0}, false);

    // Robot 2: Forklift AGV 48V, bergerak 1.5 m/s
    Robot robot2({85, 48.0}, {1.5, 0.0}, false);

    // Memanggil public member function untuk melihat status
    std::cout << "=== Robot 1 ===\n";
    robot1.printStatus();

    std::cout << "\n=== Robot 2 ===\n";
    robot2.printStatus();

    return 0;
}
