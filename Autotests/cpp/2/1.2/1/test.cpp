#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cstdio>
#include <stdexcept>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

// функция запускает ./student.out с заданным вводом и возвращает вывод
string runProgram(const string& input) {
    string cmd = "echo \"" + input + "\" | ./student.out";
    array<char, 128> buffer{};
    string result;
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw runtime_error("Не удалось запустить student.out");
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }
    pclose(pipe);

    // убираем перевод строки в конце
    if (!result.empty() && result.back() == '\n')
        result.pop_back();

    return result;
}

int main() {
    // компилируем студенческое решение
    if (system("g++ -std=c++17 main.cpp -o student.out") != 0) {
        cerr << "Ошибка: не удалось скомпилировать main.cpp\n";
        return 1;
    }

    vector<TestCase> tests = {
        {"hello 1 4 1", "ell"},
        {"hello -4 -1 1", "ell"},
        {"hello 4 0 -1", "olle"},
        {"hello 0 5 2", "hlo"},
        {"abcdef 5 0 -2", "fdb"},
        {"abcdef 0 6 3", "ad"},
        {"abcdef -1 -7 -1", "fedcba"},
        {"python 0 100 1", "python"},
        {"python -100 3 1", "pyt"},
        {"python 3 0 -2", "to"}
    };

    bool allPassed = true;

    for (int i = 0; i < tests.size(); i++) {
        string output = runProgram(tests[i].input);

        if (output == tests[i].expected) {
            cout << "Тест " << i+1 << ": ✅ Пройден\n";
        } else {
            cout << "Тест " << i+1 << ": ❌ Ошибка\n";
            cout << "   Ожидалось: \"" << tests[i].expected << "\"\n";
            cout << "   Получено:   \"" << output << "\"\n";
            allPassed = false;
        }
    }

    if (allPassed) {
        cout << "\nВсе тесты пройдены! 🎉\n";
    } else {
        cout << "\n⚠️ Есть ошибки в решении.\n";
    }

    return 0;
}
