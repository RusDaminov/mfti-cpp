#include <iostream>
#include <cmath> // для M_PI и pow
using namespace std;

// Функция для вычисления объёма шара
double sphere_volume(double r) {
    return (4.0 / 3.0) * M_PI * pow(r, 3);
}

// Автотесты
void run_tests() {
    double eps = 1e-9;

    // Тест 1: радиус 3
    double v1 = sphere_volume(3.0);
    double expected1 = (4.0 / 3.0) * M_PI * 27.0; // 4/3 * π * 27
    if (fabs(v1 - expected1) < eps) {
        cout << "✅ Тест 1 пройден" << endl;
    } else {
        cout << "❌ Тест 1 не пройден (ожидалось " << expected1 << ", получено " << v1 << ")" << endl;
    }

    // Тест 2: радиус 0
    double v2 = sphere_volume(0.0);
    if (fabs(v2 - 0.0) < eps) {
        cout << "✅ Тест 2 пройден" << endl;
    } else {
        cout << "❌ Тест 2 не пройден (ожидалось 0, получено " << v2 << ")" << endl;
    }

    // Тест 3: радиус 1
    double v3 = sphere_volume(1.0);
    double expected3 = (4.0 / 3.0) * M_PI;
    if (fabs(v3 - expected3) < eps) {
        cout << "✅ Тест 3 пройден" << endl;
    } else {
        cout << "❌ Тест 3 не пройден (ожидалось " << expected3 << ", получено " << v3 << ")" << endl;
    }
}

int main() {
    run_tests();

    double r = 3.0;
    double V = sphere_volume(r);

    cout.precision(15); // точность вывода
    cout << "Объём шара: " << fixed << V << endl;

    return 0;
}
