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
    vector<TestCase> tests = {
        {"aabbc\n", "a"},
        {"abacabad\n", "a"},
        {"zzzzzz\n", "z"},
        {"abcde\n", "a"},
        {"mississippi\n", "i"},
        {"banana\n", "a"},
        {"abracadabra\n", "a"},
        {"qwertyy\n", "y"},
        {"ccccbbbbaaaa\n", "c"},
        {"x\n", "x"}
    };

    bool allPassed = true;

    for (int i = 0; i < tests.size(); i++) {
        // создаём input.txt
        ofstream fin("input.txt");
        fin << tests[i].input;
        fin.close();

        // запускаем студенческую программу
        system("./student.out < input.txt > output.txt");

        // читаем вывод
        ifstream fout("output.txt");
        string output;
        fout >> output; // читаем первое "слово" (символ)
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

    if (allPassed) {
        cout << "\nВсе тесты пройдены! 🎉\n";
    } else {
        cout << "\n⚠️ Есть ошибки в решении.\n";
    }

    return 0;
}
