// ============================================================
// Program 06b: For Loop Dasar
// Deskripsi : For loop paling sederhana - mencetak langkah
//             robot sebanyak 5 kali.
// Konsep    : - for (inisialisasi; kondisi; increment)
//             - int i = 0: mulai dari 0
//             - i < 5: selama i kurang dari 5
//             - i++: setiap iterasi i bertambah 1
// ============================================================

#include <iostream>

int main()
{
    // Loop dari i=0 hingga i<5 (0,1,2,3,4 = 5 iterasi)
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Robot Move Step : " << i << '\n';
    }

    return 0;
}
