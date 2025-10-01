#include <iostream>
#include <string>
using namespace std;

// Функция для вычисления направления
string get_direction(int x1, int y1, int x2, int y2, int x, int y) {
    string ans;

    if (y > y2)
        ans += 'N';
    if (y < y1)
        ans += 'S';
    if (x < x1)
        ans += 'W';
    if (x > x2)
        ans += 'E';

    return ans;
}

// Автотесты
void run_tests() {
    string res;

    // Тест 1: точка выше прямоугольника
    res = get_direction(0, 0, 5, 5, 3, 7); // над верхней границей
    if (res == "N") cout << "✅ Тест 1 пройден" << endl;
    else cout << "❌ Тест 1 не пройден (ожидалось N, получено " << res << ")" << endl;

    // Тест 2: точка ниже прямоугольника
    res = get_direction(0, 0, 5, 5, 2, -1);
    if (res == "S") cout << "✅ Тест 2 пройден" << endl;
    else cout << "❌ Тест 2 не пройден (ожидалось S, получено " << res << ")" << endl;

    // Тест 3: точка левее прямоугольника
    res = get_direction(0, 0, 5, 5, -2, 3);
    if (res == "W") cout << "✅ Тест 3 пройден" << endl;
    else cout << "❌ Тест 3 не пройден (ожидалось W, получено " << res << ")" << endl;

    // Тест 4: точка правее прямоугольника
    res = get_direction(0, 0, 5, 5, 10, 2);
    if (res == "E") cout << "✅ Тест 4 пройден" << endl;
    else cout << "❌ Тест 4 не пройден (ожидалось E, получено " << res << ")" << endl;

    // Тест 5: точка внутри прямоугольника
    res = get_direction(0, 0, 5, 5, 2, 3);
    if (res == "") cout << "✅ Тест 5 пройден" << endl;
    else cout << "❌ Тест 5 не пройден (ожидалось пусто, получено " << res << ")" << endl;

    // Тест 6: точка в левом верхнем углу (W + N)
    res = get_direction(0, 0, 5, 5, -1, 7);
    if (res == "NW") cout << "✅ Тест 6 пройден" << endl;
    else cout << "❌ Тест 6 не пройден (ожидалось NW, получено " << res << ")" << endl;
}

int main() {
    run_tests();

    int x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

    cout << get_direction(x1, y1, x2, y2, x, y) << endl;

    return 0;
}
