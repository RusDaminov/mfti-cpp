#include <iostream>
using namespace std;

// Функция для вычисления результата
// Возвращает true, если k ≠ 0, и false при делении на ноль
bool calc_result(int n, int k, int &result) {
    if (k == 0) {
        return false; // ошибка деления
    }
    result = 2 * n * (n / k - 1);
    return true;
}

// Автотесты
void run_tests() {
    int res;

    // Тест 1: обычное деление
    if (calc_result(10, 2, res) && res == 80) {
        cout << "✅ Тест 1 пройден" << endl;
    } else {
        cout << "❌ Тест 1 не пройден" << endl;
    }

    // Тест 2: деление на ноль
    if (!calc_result(5, 0, res)) {
        cout << "✅ Тест 2 пройден (деление на ноль корректно обработано)" << endl;
    } else {
        cout << "❌ Тест 2 не пройден" << endl;
    }

    // Тест 3: n < k (n/k = 0 → n/k - 1 = -1)
    if (calc_result(3, 5, res) && res == -6) {
        cout << "✅ Тест 3 пройден" << endl;
    } else {
        cout << "❌ Тест 3 не пройден" << endl;
    }

    // Тест 4: n == k (n/k = 1 → n/k - 1 = 0)
    if (calc_result(7, 7, res) && res == 0) {
        cout << "✅ Тест 4 пройден" << endl;
    } else {
        cout << "❌ Тест 4 не пройден" << endl;
    }

    // Тест 5: отрицательные числа
    if (calc_result(-10, 2, res) && res == -120) {
        cout << "✅ Тест 5 пройден" << endl;
    } else {
        cout << "❌ Тест 5 не пройден" << endl;
    }
}

int main() {
    run_tests();

    int n, k;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите k: ";
    cin >> k;

    int result;
    if (calc_result(n, k, result)) {
        cout << "Результат: " << result << endl;
    } else {
        cout << "Ошибка: деление на ноль!" << endl;
    }

    return 0;
}
