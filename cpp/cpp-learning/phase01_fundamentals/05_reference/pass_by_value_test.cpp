// Reference adalah sebuah alias untuk sebuah variabel. Reference tidak dapat diubah untuk mereferensikan variabel lain setelah dideklarasikan. Reference harus diinisialisasi pada saat deklarasi. Reference tidak memiliki alamat memori sendiri, melainkan menggunakan alamat memori dari variabel yang direferensikan. Reference digunakan untuk menghindari penyalinan data yang besar dan untuk memungkinkan fungsi mengubah nilai dari argumen yang diteruskan.
#include <iostream>
#include <string>

void printName(const std::string &name)
{
    std::cout << "Robot : " << name << '\n';
}

int main()
{
    std::string robot = "NUIN-AMR-01";

    printName(robot);

    std::cout << "Di main : " << robot << '\n';

    return 0;
}
