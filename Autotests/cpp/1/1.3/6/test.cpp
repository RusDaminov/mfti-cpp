#include <iostream>
using namespace std;

// Функция для вычисления результата
// Возвращает true, если деление успешно, и false, если деление на ноль
bool calc_result(int a, int b, int c, int &ans) {
    int denominator = 3 * a + 2 * b;
    if (denominator == 0) {
        return false; // ошибка деления
    } else {
        ans = c / denominator; // целочисленное деление
        return true;
    }
}

// Автотесты
void run_tests() {
    int ans;

    // Тест 1: обычное деление
    if (calc_result(1, 1, 10, ans) && ans == 2) {
        cout << "✅ Тест 1 пройден" << endl;
    } else {
        cout << "❌ Тест 1 не пройден" << endl;
    }

    // Тест 2: деление на ноль
    if (!calc_result(0, 0, 5, ans)) {
        cout << "✅ Тест 2 пройден (корректно отловили деление на ноль)" << endl;
    } else {
        cout << "❌ Тест 2 не пройден" << endl;
    }

    // Тест 3: отрицательные значения
    if (calc_result(-1, 0, 9, ans) && ans == -3) {
        cout << "✅ Тест 3 пройден" << endl;
    } else {
        cout << "❌ Тест 3 не пройден" << endl;
    }

    // Тест 4: остаток от деления отбрасывается
    if (calc_result(2, 1, 10, ans) && ans == 1) { 
        // (3*2 + 2*1 = 8), 10 / 8 = 1 (целочисленное деление)
        cout << "✅ Тест 4 пройден" << endl;
    } else {
        cout << "❌ Тест 4 не пройден" << endl;
    }
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

    int ans;
    if (calc_result(a, b, c, ans)) {
        cout << "Результат: " << ans << endl;
    } else {
        cout << "Ошибка: деление на ноль!" << endl;
    }

    return 0;
}
