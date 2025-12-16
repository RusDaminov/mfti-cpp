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
        // исправленные ожидаемые значения (1 и 6)
        {"4 2 5\n0123\n123\n321\n0123\n", "1\n"},
        {"3 3 7\n0\n1\n2\n", "0\n"},
        {"5 10 100\n1\n11\n111\n1111\n11111\n", "6\n"},
        {"2 2 100\n123\n321\n", "0\n"},
        {"6 2 13\n1\n2\n3\n4\n5\n6\n", "0\n"}
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

        system("./main < input.txt > output.txt");

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
