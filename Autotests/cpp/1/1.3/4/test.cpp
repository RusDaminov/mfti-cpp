#include <iostream>
#include <cmath> // для sqrt()
using namespace std;

// Функция вычисления площади по формуле Герона
double triangle_area(double a, double b, double c) {
    double p = (a + b + c) / 2.0; // полупериметр
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Автотесты
void run_tests() {
    double eps = 1e-9;

    // Тест 1: (5, 6, 7) — классический пример
    double s1 = triangle_area(5.0, 6.0, 7.0);
    double expected1 = 14.6969384567;
    if (fabs(s1 - expected1) < eps) {
        cout << "✅ Тест 1 пройден" << endl;
    } else {
        cout << "❌ Тест 1 не пройден (ожидалось " << expected1 << ", получено " << s1 << ")" << endl;
    }

    // Тест 2: прямоугольный треугольник (3, 4, 5) → площадь = 6
    double s2 = triangle_area(3.0, 4.0, 5.0);
    double expected2 = 6.0;
    if (fabs(s2 - expected2) < eps) {
        cout << "✅ Тест 2 пройден" << endl;
    } else {
        cout << "❌ Тест 2 не пройден (ожидалось " << expected2 << ", получено " << s2 << ")" << endl;
    }

    // Тест 3: равносторонний треугольник (a = b = c = 2) → площадь = sqrt(3)
    double s3 = triangle_area(2.0, 2.0, 2.0);
    double expected3 = sqrt(3.0);
    if (fabs(s3 - expected3) < eps) {
        cout << "✅ Тест 3 пройден" << endl;
    } else {
        cout << "❌ Тест 3 не пройден (ожидалось " << expected3 << ", получено " << s3 << ")" << endl;
    }

    // Тест 4: вырожденный треугольник (1, 2, 3) → площадь = 0
    double s4 = triangle_area(1.0, 2.0, 3.0);
    double expected4 = 0.0;
    if (fabs(s4 - expected4) < eps) {
        cout << "✅ Тест 4 пройден" << endl;
    } else {
        cout << "❌ Тест 4 не пройден (ожидалось " << expected4 << ", получено " << s4 << ")" << endl;
    }
}

int main() {
    run_tests();

    double a = 5.0;
    double b = 6.0;
    double c = 7.0;

    double S = triangle_area(a, b, c);

    cout.precision(15); // точность вывода
    cout << "Площадь треугольника: " << fixed << S << endl;

    return 0;
}
