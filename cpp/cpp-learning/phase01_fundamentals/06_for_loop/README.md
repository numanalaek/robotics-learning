# 06 — For Loop

Penggunaan `for` loop untuk membaca dan memproses data sensor array.

## Program

### `for_loop.cpp`
Membaca 8 sensor jarak, menghitung statistik (min, max, average), dan menentukan status robot (SAFE / CAUTION / EMERGENCY).

### `for_loop_test1.cpp`
Loop sederhana mencetak langkah robot 0–4.

### `hitung_battery_test2.cpp`
Simulasi pengurangan baterai setiap langkah dengan `sleep_for`.

### `array_robot_sensor_test3.cpp`
Loop untuk membaca 5 sensor ultrasonic.

### `simulasi_pembacaan_sensor_test4.cpp`
Loop 7 sensor — menampilkan `OBSTACLE` jika jarak < 100 cm, `CLEAR` jika >= 100 cm.

### `robot_monitor.cpp`
Mirip `for_loop.cpp` — membaca 8 sensor, menghitung total warning jika jarak < 50 cm.

## Konsep

- `for` loop dengan counter (`int i = 0; i < N; ++i`)
- Array indexing `sensors[i]`
- Akumulasi nilai (`sum += sensors[i]`)
- Mencari nilai minimum/maksimum dalam array
- `static_cast<double>` untuk konversi tipe
- `std::this_thread::sleep_for` untuk simulasi waktu nyata
