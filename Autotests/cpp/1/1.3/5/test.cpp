#include <iostream>
#include <algorithm> // для std::min
using namespace std;

// Функция для вычисления минимального значения
int calc_min(int a, int b, int c) {
    int val1 = 4 * a;
    int val2 = 2 * b + 1;
    int val3 = 4 * c + 2;
    return min(val1, min(val2, val3));
}

// Автотесты
void run_tests() {
    // Тест 1
    int r1 = calc_min(1, 2, 3); 
    // val1 = 4, val2 = 5, val3 = 14 → минимум = 4
    if (r1 == 4) cout << "✅ Тест 1 пройден" << endl;
    else cout << "❌ Тест 1 не пройден (ожидалось 4, получено " << r1 << ")" << endl;

    // Тест 2
    int r2 = calc_min(0, 0, 0); 
    // val1 = 0, val2 = 1, val3 = 2 → минимум = 0
    if (r2 == 0) cout << "✅ Тест 2 пройден" << endl;
    else cout << "❌ Тест 2 не пройден (ожидалось 0, получено " << r2 << ")" << endl;

    // Тест 3
    int r3 = calc_min(5, 1, 1);
    // val1 = 20, val2 = 3, val3 = 6 → минимум = 3
    if (r3 == 3) cout << "✅ Тест 3 пройден" << endl;
    else cout << "❌ Тест 3 не пройден (ожидалось 3, получено " << r3 << ")" << endl;

    // Тест 4 (отрицательные числа)
    int r4 = calc_min(-2, -1, -3);
    // val1 = -8, val2 = -1, val3 = -10 → минимум = -10
    if (r4 == -10) cout << "✅ Тест 4 пройден" << endl;
    else cout << "❌ Тест 4 не пройден (ожидалось -10, получено " << r4 << ")" << endl;
}

int main() {
    run_tests();

    int a, b, c;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите c: ";
    cin >> c;

    int result = calc_min(a, b, c);
    cout << "Минимальное значение: " << result << endl;

    return 0;
}
