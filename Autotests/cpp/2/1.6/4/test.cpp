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
        {"3\n5\n3\n5\n", "120\n6\n120\n"},
        {"2\n0\n1\n", "1\n1\n"},
        {"4\n2\n4\n2\n3\n", "2\n24\n2\n6\n"},
        {"1\n10\n", "3628800\n"},
        {"5\n6\n7\n6\n8\n7\n", "720\n5040\n720\n40320\n5040\n"}
    };

    int passed = 0, total = tests.size();

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
            cout << "Тест " << i + 1 << " пройден ✅\n";
            passed++;
        } else {
            cout << "Тест " << i + 1 << " провален ❌\n";
            cout << "Ожидалось:\n" << tests[i].expected;
            cout << "Получено:\n" << result;
        }
    }

    cout << "\nРезультат: " << passed << "/" << total << " тестов успешно.\n";
    return 0;
}
