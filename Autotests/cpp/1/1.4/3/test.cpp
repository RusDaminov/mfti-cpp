#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm> // для std::remove
using namespace std;

// Кроссплатформенное имя исполняемого файла
#ifdef _WIN32
const string exeName = "main.exe";
#else
const string exeName = "main";
#endif

// Структура теста
struct TestCase {
    string input;
    string expected;
    string comment;
};

// Функция для запуска программы и получения вывода
string runProgram(const string& input) {
    // создаём input.txt
    ofstream fin("input.txt");
    fin << input;
    fin.close();

    // компиляция main.cpp
    string compileCmd = "g++ -std=c++11 -w main.cpp -o " + exeName;
    int compileResult = system(compileCmd.c_str());
    if (compileResult != 0) {
        cerr << "❌ Ошибка компиляции main.cpp" << endl;
        exit(1);
    }

    // запуск с redirection
#ifdef _WIN32
    string runCmd = exeName + " < input.txt > output.txt";
#else
    string runCmd = "./" + exeName + " < input.txt > output.txt";
#endif
    int runResult = system(runCmd.c_str());
    if (runResult != 0) {
        cerr << "❌ Ошибка при запуске программы" << endl;
        exit(1);
    }

    // читаем вывод
    ifstream fout("output.txt");
    stringstream buffer;
    buffer << fout.rdbuf();
    fout.close();
    string output = buffer.str();

    // Удаляем переводы строк и пробелы
    output.erase(std::remove(output.begin(), output.end(), '\n'), output.end());
    output.erase(std::remove(output.begin(), output.end(), '\r'), output.end());
    output.erase(std::remove(output.begin(), output.end(), ' '), output.end());

    return output;
}

int main() {
    vector<TestCase> tests = {
        {"0\n0\n3\n4\n", "EEENNNN", "Простой случай"},
        {"5\n5\n5\n5\n", "", "Начало и конец совпадают"},
        {"2\n7\n-1\n3\n", "WWWSSSS", "Отрицательное движение"},
        {"-3\n0\n0\n5\n", "EEENNNNN", "С отрицательными координатами"},
        {"10\n10\n10\n0\n", "SSSSSSSSSS", "Только вертикальное движение"}
    };

    cout << "=== ТЕСТИРОВАНИЕ ЗАДАЧИ «МАНХЭТТЕН» ===" << endl;

    int passed = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        cout << "\nТест #" << (i + 1) << ": " << tests[i].comment << endl;

        string result = runProgram(tests[i].input);

        if (result == tests[i].expected) {
            cout << "✅ Пройден. Вывод: " << (result.empty() ? "(пусто)" : result) << endl;
            passed++;
        } else {
            cout << "❌ Провален." << endl;
            cout << "   Ожидалось: \"" << tests[i].expected << "\"" << endl;
            cout << "   Получено:   \"" << result << "\"" << endl;
        }
    }

    cout << "\n==============================" << endl;
    cout << "Пройдено тестов: " << passed << " из " << tests.size() << endl;
    cout << "==============================" << endl;

    return 0;
}
