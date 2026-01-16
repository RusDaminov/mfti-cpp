#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TestCase {
    string input;
    string expected;
};

int main() {
    vector<TestCase> tests = {
        {"ababa\n", "9\n"},
        {"aaa\n", "3\n"},
        {"abc\n", "6\n"},
        {"abcd\n", "10\n"},
        {"aab\n", "5\n"}
    };

    int passed = 0;
    int total = tests.size();

    // Компиляция main.cpp
    if (system("g++ -std=c++11 -w main.cpp -o main") != 0) {
        cerr << "Ошибка компиляции main.cpp" << endl;
        return 1;
    }

    for (size_t i = 0; i < tests.size(); ++i) {
        ofstream input("input.txt");
        input << tests[i].input;
        input.close();

        // Запуск программы
        system("./main < input.txt > output.txt");

        // Считывание вывода
        ifstream output("output.txt");
        string result((istreambuf_iterator<char>(output)), istreambuf_iterator<char>());
        output.close();

        if (result == tests[i].expected) {
            cout << "Тест " << i + 1 << " пройден ✅" << endl;
            passed++;
        } else {
            cout << "Тест " << i + 1 << " провален ❌" << endl;
            cout << "Ожидалось: " << tests[i].expected;
            cout << "Получено:  " << result;
        }
    }

    cout << "\nРезультат: " << passed << "/" << total << " тестов успешно.\n";
    return 0;
}
