#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct Test {
    string input;
    string expected;
};

int main() {
    vector<Test> tests = {
        {"1 2 3", "1 2 3"},
        {"5", "5"},
        {"", ""},
        {"10 -1 7", "10 -1 7"},
        {"0 0 0", "0 0 0"}
    };

    // Компиляция main.cpp
#ifdef _WIN32
    const string compileCmd = "g++ -std=c++11 -w main.cpp -o main.exe";
    const string runCmd = "main.exe";
#else
    const string compileCmd = "g++ -std=c++11 -w main.cpp -o main.out";
    const string runCmd = "./main.out";
#endif

    if (system(compileCmd.c_str()) != 0) {
        cout << "❌ Ошибка компиляции main.cpp\n";
        return 1;
    }

    cout << "✅ Компиляция успешна\n\n";

    for (size_t i = 0; i < tests.size(); ++i) {
        // Записываем входные данные
        ofstream fin("input.txt");
        fin << tests[i].input;
        fin.close();

        // Запуск программы
        string cmd = runCmd + " < input.txt > output.txt";
        system(cmd.c_str());

        // Читаем вывод
        ifstream fout("output.txt");
        string output;
        getline(fout, output);
        fout.close();

        cout << "Тест #" << i + 1 << ": ";
        if (output == tests[i].expected) {
            cout << "OK\n";
        } else {
            cout << "FAIL\n";
            cout << "  Ожидалось: [" << tests[i].expected << "]\n";
            cout << "  Получено:  [" << output << "]\n";
        }
    }

    return 0;
}
