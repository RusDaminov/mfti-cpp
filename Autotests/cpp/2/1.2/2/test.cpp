#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

int main() {
    // сначала компилируем студенческое решение
    if (system("g++ -std=c++17 main.cpp -o student.out") != 0) {
        cerr << "Ошибка: не удалось скомпилировать main.cpp\n";
        return 1;
    }

    vector<TestCase> tests = {
        {"hello l\n", "2"},
        {"hello lo\n", "3"},
        {"hello x\n", "-1"},
        {"aaaaa aa\n", "0"},
        {"abcdef def\n", "3"},
        {"abcdef ghi\n", "-1"},
        {"abcabc abc\n", "0"},
        {"abcabc cab\n", "2"},
        {"abcabc bca\n", "1"},
        {"abracadabra abra\n", "0"}
    };

    bool allPassed = true;

    for (int i = 0; i < tests.size(); i++) {
        ofstream fin("input.txt");
        fin << tests[i].input;
        fin.close();

        system("./student.out < input.txt > output.txt");

        ifstream fout("output.txt");
        string output;
        getline(fout, output);
        fout.close();

        if (output == tests[i].expected) {
            cout << "Тест " << i+1 << ": ✅ Пройден\n";
        } else {
            cout << "Тест " << i+1 << ": ❌ Ошибка\n";
            cout << "   Ожидалось: \"" << tests[i].expected << "\"\n";
            cout << "   Получено:   \"" << output << "\"\n";
            allPassed = false;
        }
    }

    if (allPassed)
        cout << "\nВсе тесты пройдены! 🎉\n";
    else
        cout << "\n⚠️ Есть ошибки в решении.\n";

    return 0;
}
