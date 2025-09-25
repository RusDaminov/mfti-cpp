#include <iostream>
using namespace std;

// Функция нахождения среднего по величине
int middle(int a, int b, int c) {
    if ((a <= b && b <= c) || (c <= b && b <= a))
        return b;
    else if ((b <= a && a <= c) || (c <= a && a <= b))
        return a;
    else
        return c;
}

// Автотесты
void run_tests() {
    int res;

    // Тест 1: упорядоченные по возрастанию
    res = middle(1, 2, 3);
    if (res == 2) cout << "✅ Тест 1 пройден" << endl;
    else cout << "❌ Тест 1 не пройден (ожидалось 2, получено " << res << ")" << endl;

    // Тест 2: упорядоченные по убыванию
    res = middle(9, 5, 1);
    if (res == 5) cout << "✅ Тест 2 пройден" << endl;
    else cout << "❌ Тест 2 не пройден (ожидалось 5, получено " << res << ")" << endl;

    // Тест 3: средний первый
    res = middle(5, 9, 7);
    if (res == 7) cout << "✅ Тест 3 пройден" << endl;
    else cout << "❌ Тест 3 не пройден (ожидалось 7, получено " << res << ")" << endl;

    // Тест 4: равные значения
    res = middle(4, 4, 7);
    if (res == 4) cout << "✅ Тест 4 пройден" << endl;
    else cout << "❌ Тест 4 не пройден (ожидалось 4, получено " << res << ")" << endl;

    // Тест 5: все равны
    res = middle(3, 3, 3);
    if (res == 3) cout << "✅ Тест 5 пройден" << endl;
    else cout << "❌ Тест 5 не пройден (ожидалось 3, получено " << res << ")" << endl;

    // Тест 6: отрицательные числа
    res = middle(-10, -5, -20);
    if (res == -10) cout << "✅ Тест 6 пройден" << endl;
    else cout << "❌ Тест 6 не пройден (ожидалось -10, получено " << res << ")" << endl;
}

int main() {
    run_tests();

    int a, b, c;
    cin >> a >> b >> c;
    cout << middle(a, b, c) << endl;

    return 0;
}
