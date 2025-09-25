#include <iostream>
#include <string>
using namespace std;

// Функция для построения пути
string build_path(int x1, int y1, int x2, int y2) {
    string path;

    // Движение по X
    if (x2 > x1) {
        path.append(x2 - x1, 'E');
    } else {
        path.append(x1 - x2, 'W');
    }

    // Движение по Y
    if (y2 > y1) {
        path.append(y2 - y1, 'N');
    } else {
        path.append(y1 - y2, 'S');
    }

    return path;
}

// Автотесты
void run_tests() {
    string res;

    // Тест 1: вправо и вверх
    res = build_path(0, 0, 2, 3);
    if (res == "EENN N") // 2 раза E и 3 раза N
        cout << "✅ Тест 1 пройден" << endl;
    else
        cout << "❌ Тест 1 не пройден (ожидалось EENN N, получено " << res << ")" << endl;

    // Тест 2: влево и вниз
    res = build_path(5, 5, 2, 3);
    if (res == "WWWSS") // 3 раза W и 2 раза S
        cout << "✅ Тест 2 пройден" << endl;
    else
        cout << "❌ Тест 2 не пройден (ожидалось WWWSS, получено " << res << ")" << endl;

    // Тест 3: только по X
    res = build_path(1, 1, 4, 1);
    if (res == "EEE")
        cout << "✅ Тест 3 пройден" << endl;
    else
        cout << "❌ Тест 3 не пройден (ожидалось EEE, получено " << res << ")" << endl;

    // Тест 4: только по Y
    res = build_path(2, 7, 2, 4);
    if (res == "SSS")
        cout << "✅ Тест 4 пройден" << endl;
    else
        cout << "❌ Тест 4 не пройден (ожидалось SSS, получено " << res << ")" << endl;

    // Тест 5: та же точка
    res = build_path(3, 3, 3, 3);
    if (res == "")
        cout << "✅ Тест 5 пройден" << endl;
    else
        cout << "❌ Тест 5 не пройден (ожидалось пусто, получено " << res << ")" << endl;
}

int main() {
    run_tests();

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    string path = build_path(x1, y1, x2, y2);

    // Вывод по шагам, как в твоём коде
    for (char c : path) {
        cout << c << "\n";
    }

    return 0;
}
