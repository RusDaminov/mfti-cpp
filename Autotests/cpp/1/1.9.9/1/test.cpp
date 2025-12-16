#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

// Структура для теста
struct TestCase {
    string input;
    string expected;
    string comment;
};

// Функция запуска main.cpp и получения вывода
string runProgram(const string& input) {
    ofstream fin("input.txt");
    fin << input;
    fin.close();

    // Компиляция main.cpp
    system("g++ -std=c++11 -w main.cpp -o main.exe");

    // Запуск программы с перенаправлением ввода/вывода
#ifdef _WIN32
    system("main.exe < input.txt > output.txt");
#else
    system("./main.exe < input.txt > output.txt");
#endif

    ifstream fout("output.txt");
    stringstream buffer;
    buffer << fout.rdbuf();
    string output = buffer.str();

    // Убираем лишние пробелы и переносы строк
    output.erase(remove(output.begin(), output.end(), '\n'), output.end());
    output.erase(remove(output.begin(), output.end(), '\r'), output.end());
    while (!output.empty() && output.back() == ' ')
        output.pop_back();

    return output;
}

int main() {
    vector<TestCase> tests = {
        {"5\n1 3 4 2 5\n", "5 3 4 2 1", "Минимум в начале, максимум в конце"},
        {"4\n7 7 7 7\n", "7 7 7 7", "Все элементы одинаковы"},
        {"6\n2 5 1 5 1 3\n", "5 2 1 5 1 3", "Первый минимум и первый максимум"},
        {"3\n3 1 2\n", "1 3 2", "Массив маленький, обмен первой пары"},
        {"7\n4 6 1 9 3 1 2\n", "4 6 9 1 3 1 2", "Первый минимум и первый максимум в середине"}
    };

    cout << "=== ТЕСТИРОВАНИЕ ЗАДАЧИ 'МИНИМУМ-МАКСИМУМ' ===" << endl;

    int passed = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        cout << "\nТест #" << (i + 1) << ": " << tests[i].comment << endl;
        string result = runProgram(tests[i].input);
        if (result == tests[i].expected) {
            cout << "✔ Пройден. Вывод: " << result << endl;
            passed++;
        } else {
            cout << "✗ Ошибка" << endl;
            cout << "   Ожидалось: " << tests[i].expected << endl;
            cout << "   Получено:  " << result << endl;
        }
    }

    cout << "\n=== ИТОГ ===" << endl;
    cout << "Пройдено тестов: " << passed << " из " << tests.size() << endl;
    return 0;
}
