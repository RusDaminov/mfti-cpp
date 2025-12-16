#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

// Правильная нормализация: убираем лишние пробелы и переводы строк
string normalize(const string& s) {
    stringstream result;
    bool need_space = false;
    for (char c : s) {
        if (isspace(c)) {
            need_space = true;
        } else {
            if (need_space && !result.str().empty()) {
                result << ' ';
            }
            result << c;
            need_space = false;
        }
    }
    return result.str();
}

int main() {
    vector<tuple<string, string, string>> tests = {
        {"5\n4\n2\n3\n5\n1\n",        "1 4 3 5 2", "Пример из условия (n=5)"},
        {"1\n1\n",                    "1",         "n=1"},
        {"2\n1\n2\n",                 "2 1",       "n=2, главная диагональ"},
        {"2\n2\n1\n",                 "1 2",       "n=2, антидиагональ"},
        {"4\n3\n1\n4\n2\n",           "3 1 4 2",   "n=4 — правильный ответ!"},
        {"3\n3\n2\n1\n",              "1 2 3",     "антидиагональ → главная диагональ"}
    };

    cout << "Запуск тестов для main.cpp...\n\n";

    bool all_passed = true;

    for (size_t i = 0; i < tests.size(); ++i) {
        auto [input_data, expected, name] = tests[i];

        // Записываем входные данные
        ofstream("input.txt") << input_data;

        // Компилируем (поддержка clang++ и g++)
        int compile_ok = system("clang++ -std=c++17 -O2 -Wall main.cpp -o program 2> compile_err.txt");
        if (compile_ok != 0) {
            compile_ok = system("g++ -std=c++17 -O2 -Wall main.cpp -o program 2> compile_err.txt");
        }

        if (compile_ok != 0) {
            cout << "ОШИБКА: Не удалось скомпилировать main.cpp\n";
            system("cat compile_err.txt 2>/dev/null || type compile_err.txt 2>nul");
            return 1;
        }

        // Запускаем программу
        system("./program < input.txt > output.txt 2>/dev/null || .\\program.exe < input.txt > output.txt 2>nul");

        // Читаем вывод
        ifstream out("output.txt");
        stringstream buffer;
        buffer << out.rdbuf();
        string actual = buffer.str();

        string actual_norm = normalize(actual);
        string expected_norm = normalize(expected);

        cout << "Тест " << (i + 1) << " (" << name << "): ";

        if (actual_norm == expected_norm) {
            cout << "OK\n";
        } else {
            cout << "FAIL\n";
            cout << "   Ожидалось: [" << expected << "]\n";
            cout << "   Получено : [" << actual << "]\n";
            all_passed = false;
        }
    }

    cout << "\n";
    if (all_passed) {
        cout << "ВСЕ ТЕСТЫ ПРОЙДЕНЫ! Отличная работа!\n";
    } else {
        cout << "НЕКОТОРЫЕ ТЕСТЫ НЕ ПРОШЛИ — смотри ошибки выше.\n";
    }

    // Уборка (необязательно)
    // system("rm -f input.txt output.txt program compile_err.txt 2>/dev/null || del input.txt output.txt program.exe compile_err.txt 2>nul");

    return all_passed ? 0 : 1;
}