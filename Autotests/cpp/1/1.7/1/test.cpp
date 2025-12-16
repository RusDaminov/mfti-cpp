#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

#ifdef _WIN32
const string exeName = "main.exe";
#else
const string exeName = "main";
#endif

// Описание теста
struct TestCase {
    string input;
    string expected;
    string comment;
};

// Функция запуска тестируемой программы
string runProgram(const string& input) {
    // Пишем input.txt
    ofstream fin("input.txt");
    fin << input;
    fin.close();

    // Компилируем main.cpp
    string compileCmd = "g++ -std=c++11 -w main.cpp -o " + exeName;
    if (system(compileCmd.c_str()) != 0) {
        cerr << "❌ Ошибка компиляции main.cpp\n";
        exit(1);
    }

    // Запускаем
    string runCmd;
#ifdef _WIN32
    runCmd = exeName + " < input.txt > output.txt";
#else
    runCmd = "./" + exeName + " < input.txt > output.txt";
#endif

    if (system(runCmd.c_str()) != 0) {
        cerr << "❌ Ошибка выполнения программы\n";
        exit(1);
    }

    // Читаем output.txt
    ifstream fout("output.txt");
    stringstream buffer;
    buffer << fout.rdbuf();
    fout.close();

    string output = buffer.str();

    // Убираем \n, \r и пробелы
    output.erase(remove(output.begin(), output.end(), '\n'), output.end());
    output.erase(remove(output.begin(), output.end(), '\r'), output.end());
    output.erase(remove(output.begin(), output.end(), ' '), output.end());

    return output;
}

int main() {
    vector<TestCase> tests = {
        {"hello world\nworld\n", "6", "Вхождение в середине"},
        {"abcdef\ncd\n", "2", "Простое вхождение"},
        {"aaaaa\naa\n", "0", "Перекрывающиеся подстроки"},
        {"abcdef\nxyz\n", "-1", "Нет вхождения"},
        {"abc\nabc\n", "0", "Полное совпадение"},
        {"abc\nabcd\n", "-1", "Шаблон длиннее текста"},
        {"\n\n", "0", "Обе строки пустые → пустая подстрока найдена в позиции 0"},
        {"abc\n\n", "0", "Пустой pattern всегда найден в позиции 0"},
        {"\nabc\n", "-1", "Пустой text, непустой pattern → -1"}
    };

    cout << "=== ТЕСТИРОВАНИЕ ФУНКЦИИ find_substring ===\n";

    int passed = 0;

    for (size_t i = 0; i < tests.size(); ++i) {
        cout << "\nТест #" << i + 1 << ": " << tests[i].comment << endl;

        string result = runProgram(tests[i].input);

        if (result == tests[i].expected) {
            cout << "✅ Пройден: " << result << endl;
            passed++;
        } else {
            cout << "❌ Провален:\n";
            cout << "   Ожидалось: " << tests[i].expected << "\n";
            cout << "   Получено:  " << result << "\n";
        }
    }

    cout << "\n==============================\n";
    cout << "Пройдено тестов: " << passed << " из " << tests.size() << endl;
    cout << "==============================\n";

    return 0;
}
