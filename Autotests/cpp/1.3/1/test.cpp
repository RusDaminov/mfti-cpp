#include <iostream>
#include <cassert>
using namespace std;

// Функция вычисления площади треугольника
double triangle_area(double a, double h) {
    return 0.5 * a * h;
}

// Автотесты
void run_tests() {
    // Положительные значения
    assert(triangle_area(5, 10) == 25.0);
    assert(triangle_area(6, 8) == 24.0);

    // Нули
    assert(triangle_area(0, 10) == 0.0);
    assert(triangle_area(5, 0) == 0.0);

    // Дробные значения
    assert(triangle_area(2.5, 4.0) == 5.0);

    // Отрицательные значения (математика даст отрицательную "площадь")
    assert(triangle_area(-5, 10) == -25.0);

    cout << "✅ Все тесты пройдены!" << endl;
}

int main() {
    run_tests();

    // Пример обычного запуска
    double a = 5;
    double h = 10;
    double S = triangle_area(a, h);
    cout << "Площадь треугольника: " << S << endl;

    return 0;
}
