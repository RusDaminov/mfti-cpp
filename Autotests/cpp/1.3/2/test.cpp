#include <iostream>
#include <cmath> // Для sqrt()
using namespace std;

// Функция для вычисления расстояния между точками
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Автотесты
void run_tests() {
    double eps = 1e-9; // допустимая погрешность для сравнения вещественных чисел

    // Тест 1: пример из задачи
    double d1 = distance(1.0, 2.0, 4.0, 6.0);
    if (fabs(d1 - 5.0) < eps) {
        cout << "✅ Тест 1 пройден" << endl;
    } else {
        cout << "❌ Тест 1 не пройден (ожидалось 5, получено " << d1 << ")" << endl;
    }

    // Тест 2: одинаковые точки
    double d2 = distance(2.0, 3.0, 2.0, 3.0);
    if (fabs(d2 - 0.0) < eps) {
        cout << "✅ Тест 2 пройден" << endl;
    } else {
        cout << "❌ Тест 2 не пройден (ожидалось 0, получено " << d2 << ")" << endl;
    }

    // Тест 3: точки на оси X
    double d3 = distance(0.0, 0.0, 3.0, 0.0);
    if (fabs(d3 - 3.0) < eps) {
        cout << "✅ Тест 3 пройден" << endl;
    } else {
        cout << "❌ Тест 3 не пройден (ожидалось 3, получено " << d3 << ")" << endl;
    }

    // Тест 4: точки на оси Y
    double d4 = distance(0.0, 0.0, 0.0, -4.0);
    if (fabs(d4 - 4.0) < eps) {
        cout << "✅ Тест 4 пройден" << endl;
    } else {
        cout << "❌ Тест 4 не пройден (ожидалось 4, получено " << d4 << ")" << endl;
    }
}

int main() {
    run_tests();

    // Пример из задачи
    double x1 = 1.0;
    double y1 = 2.0;
    double x2 = 4.0;
    double y2 = 6.0;

    double d = distance(x1, y1, x2, y2);
    cout << "Расстояние между точками: " << d << endl;

    return 0;
}
