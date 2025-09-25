#include <iostream>
using namespace std;

// Функция для вычисления результата
int calc_result(int N, int K) {
    int M = (N - K + 1) / 2;
    if (M < K) {
        return 0;
    } else {
        return M - K;
    }
}

// Автотесты
void run_tests() {
    // Тест 1: обычный случай
    int r1 = calc_result(10, 3);
    // M = (10 - 3 + 1) / 2 = 8/2 = 4 → 4 < 3? нет → 4 - 3 = 1
    if (r1 == 1) cout << "✅ Тест 1 пройден" << endl;
    else cout << "❌ Тест 1 не пройден (ожидалось 1, получено " << r1 << ")" << endl;

    // Тест 2: случай, когда M < K
    int r2 = calc_result(5, 4);
    // M = (5 - 4 + 1) / 2 = 2/2 = 1 → 1 < 4 → результат 0
    if (r2 == 0) cout << "✅ Тест 2 пройден" << endl;
    else cout << "❌ Тест 2 не пройден (ожидалось 0, получено " << r2 << ")" << endl;

    // Тест 3: граница M == K
    int r3 = calc_result(7, 3);
    // M = (7 - 3 + 1) / 2 = 5/2 = 2 (целое деление) → 2 < 3 → 0
    if (r3 == 0) cout << "✅ Тест 3 пройден" << endl;
    else cout << "❌ Тест 3 не пройден (ожидалось 0, получено " << r3 << ")" << endl;

    // Тест 4: большие числа
    int r4 = calc_result(100, 10);
    // M = (100 - 10 + 1) / 2 = 91/2 = 45 → 45 >= 10 → 45 - 10 = 35
    if (r4 == 35) cout << "✅ Тест 4 пройден" << endl;
    else cout << "❌ Тест 4 не пройден (ожидалось 35, получено " << r4 << ")" << endl;

    // Тест 5: N = K
    int r5 = calc_result(6, 6);
    // M = (6 - 6 + 1) / 2 = 1/2 = 0 → 0 < 6 → результат 0
    if (r5 == 0) cout << "✅ Тест 5 пройден" << endl;
    else cout << "❌ Тест 5 не пройден (ожидалось 0, получено " << r5 << ")" << endl;
}

int main() {
    run_tests();

    int N, K;
    cout << "Введите N: ";
    cin >> N;
    cout << "Введите K: ";
    cin >> K;

    cout << calc_result(N, K) << endl;

    return 0;
}
