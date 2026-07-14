# 05 — Reference

Perbedaan pass by value, pass by reference, dan pass by const reference dalam C++.

## Program

### `pass_by_value.cpp`
Parameter berupa salinan (copy). Perubahan di fungsi tidak memengaruhi variabel asli.

### `pass_by_reference.cpp`
Parameter berupa reference (`&`). Perubahan di fungsi mengubah variabel asli karena alamatnya sama.

### `const_reference.cpp`
Parameter const reference — efisien (tanpa copy) dan aman (tidak bisa diubah).

### `pass_by_value_test.cpp` / `pass_by_reference_test.cpp` / `const_reference_test.cpp`
Variasi dan pembuktian dari ketiga metode di atas.

### `reference_test1.cpp`
Perbandingan langsung pass by value vs pass by reference — menunjukkan alamat berbeda vs sama.

### `reference_test2.cpp`
Membuktikan bahwa reference adalah alias (bukan pointer):
- `&ref == &battery` (alamat sama)
- Reference tidak punya alamat sendiri
- Berbeda dengan pointer yang punya alamat sendiri

## Konsep

| Metode              | Sintaks          | Copy? | Ubah Asli? | Efisien? |
|---------------------|------------------|-------|------------|----------|
| Pass by value       | `T x`            | Ya    | Tidak      | Tidak    |
| Pass by reference   | `T &x`           | Tidak | Ya         | Ya       |
| Pass by const ref   | `const T &x`     | Tidak | Tidak      | Ya       |
