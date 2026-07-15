// ============================================================
// Program 05f: Reference BUKAN Pointer
// Deskripsi : Membuktikan bahwa reference adalah ALIAS (nama
//             lain), bukan pointer. Reference tidak punya
//             alamat memori sendiri.
// Konsep    : - &ref == &battery (alamat SAMA)
//             - ref adalah nama lain untuk battery
//             - Berbeda dengan pointer yang punya alamat sendiri
//             - Mengubah ref = mengubah battery (dan sebaliknya)
// ============================================================

#include <iostream>

int main()
{
    std::cout << "=== Membuktikan bahwa Reference BUKAN Pointer ===\n\n";

    int battery = 100;
    int &ref = battery;     // ref adalah alias/nama lain untuk battery

    // Nilai battery dan ref selalu sama
    std::cout << "Cetak nilai:\n";
    std::cout << "  battery = " << battery << "\n";
    std::cout << "  ref     = " << ref << "\n\n";

    // Alamat battery dan ref juga SAMA
    std::cout << "Cetak alamat:\n";
    std::cout << "  &battery = " << &battery << "\n";
    std::cout << "  &ref     = " << &ref << "\n\n";

    std::cout << "Apakah &battery == &ref ? "
              << (&battery == &ref ? "YA, alamatnya SAMA" : "TIDAK SAMA") << "\n\n";

    // Ubah melalui ref -> battery ikut berubah
    std::cout << "Ubah nilai melalui ref:\n";
    ref = 75;
    std::cout << "  ref = 75;\n";
    std::cout << "  battery = " << battery << "\n";
    std::cout << "  ref     = " << ref << "\n\n";

    // Ubah melalui battery -> ref ikut berubah
    std::cout << "Ubah nilai melalui battery:\n";
    battery = 50;
    std::cout << "  battery = 50;\n";
    std::cout << "  battery = " << battery << "\n";
    std::cout << "  ref     = " << ref << "\n\n";

    std::cout << "Kesimpulan:\n";
    std::cout << "- ref dan battery adalah DUA NAMA untuk SATU VARIABEL yang sama.\n";
    std::cout << "- ref TIDAK punya alamat sendiri (&ref == &battery).\n";
    std::cout << "- Pointer punya alamat sendiri (&ptr != &battery).\n";
    std::cout << "- Reference hanyalah alias (nama lain), bukan objek terpisah.\n";

    return 0;
}
