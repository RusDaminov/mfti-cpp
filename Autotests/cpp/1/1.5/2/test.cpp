#include <iostream>
#include <utility> // для pair
using namespace std;

// Функция для разложения m на (n3, n4)
pair<int, int> decompose(int m) {
    int n4 = m % 3;
    int n3 = (m - 4 * n4) / 3;

    if (n3 >= 0)
        return {n3, n4};
    else
        return {0, 0};
}

// Автотесты
void run_tests() {
    pair<int, int> res;

    // Тест 1: m делится на 3
    res = decompose(9); // 9 = 3*3 + 4*0
    if (res.first == 3 && res.second == 0)
        cout << "✅ Тест 1 пройден" << endl;
    else
        cout << "❌ Тест 1 не пройден (ожидалось 3 0, получено "
             << res.first << " " << res.second << ")" << endl;

    // Тест 2: m делится на 4
    res = decompose(8); // 8 = 3*0 + 4*2 → n4 = 2, но у нас n4 = m % 3 = 2, n3 = 0
    if (res.first == 0 && res.second == 2)
        cout << "✅ Тест 2 пройден" << endl;
    else
        cout << "❌ Тест 2 не пройден (ожидалось 0 2, получено "
             << res.first << " " << res.second << ")" << endl;

    // Тест 3: смешанное разложение
    res = decompose(10); // 10 = 3*2 + 4*1
    if (res.first == 2 && res.second == 1)
        cout << "✅ Тест 3 пройден" << endl;
    else
        cout << "❌ Тест 3 не пройден (ожидалось 2 1, получено "
             << res.first << " " << res.second << ")" << endl;

    // Тест 4: невозможно (отрицательное n3)
    res = decompose(1);
    if (res.first == 0 && res.second == 0)
        cout << "✅ Тест 4 пройден" << endl;
    else
        cout << "❌ Тест 4 не пройден (ожидалось 0 0, получено "
             << res.first << " " << res.second << ")" << endl;

    // Тест 5: большое число
    res = decompose(100);
    // 100 % 3 = 1 → n4 = 1, n3 = (100 - 4) / 3 = 32
    if (res.first == 32 && res.second == 1)
        cout << "✅ Тест 5 пройден" << endl;
    else
        cout << "❌ Тест 5 не пройден (ожидалось 32 1, получено "
             << res.first << " " << res.second << ")" << endl;
}

int main() {
    run_tests();

    int m;
    cin >> m;
    auto [n3, n4] = decompose(m);
    cout << n3 << "\n" << n4 << "\n";

    return 0;
}
