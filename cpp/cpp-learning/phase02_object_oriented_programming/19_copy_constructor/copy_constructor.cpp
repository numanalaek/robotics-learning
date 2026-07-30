// ============================================================
// copy_constructor.cpp — Copy Constructor
// ============================================================
// Compile & run:
//   g++ copy_constructor.cpp -o copy_constructor && ./copy_constructor
// ============================================================

#include <iostream>
#include <string>

class Robot
{
private:
    std::string name_; // trailing underscore _

public:
    // --- Constructor (dipanggil saat objek dibuat dari string) ---
    Robot(const std::string &name)
        : name_(name)
    {
        std::cout << "Constructor : "
                  << name_
                  << '\n';
    }

    // --- Copy Constructor (dipanggil saat objek dibuat dari objek lain) ---
    // Menerima const reference ke object lain, lalu menyalin member-nya.
    Robot(const Robot &other)
        : name_(other.name_)
    {
        std::cout
            << "Copy Constructor : "
            << name_
            << '\n';
    }

    // --- Print name ---
    void print() const
    {
        std::cout
            << "Robot = "
            << name_
            << '\n';
    }

    // --- Get address of name_ (untuk demonstrasi memory) ---
    // Digunakan hanya untuk demonstrasi bahwa hasil copy
    // memiliki alamat member yang berbeda.
    const std::string *getNameAddress() const
    {
        return &name_;
    }
};

int main()
{
    Robot robot1("NUIN-AMR-01"); // Constructor

    std::cout << '\n';

    Robot robot2 = robot1; // Copy Constructor

    std::cout << '\n';

    robot1.print(); // Robot = NUIN-AMR-01
    robot2.print(); // Robot = NUIN-AMR-01 (salinan)

    std::cout << "\nObject Address\n";
    std::cout << "&robot1 = " << &robot1 << '\n';
    std::cout << "&robot2 = " << &robot2 << '\n';

    std::cout << "\nMember Address\n";
    std::cout << "robot1.name_ = " << robot1.getNameAddress() << '\n';
    std::cout << "robot2.name_ = " << robot2.getNameAddress() << '\n';
    std::cout << "(alamat berbeda -> object berbeda)\n";
}
