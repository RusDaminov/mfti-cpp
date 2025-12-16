// test.cpp
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

// Функция компиляции main.cpp
bool compileMain() {
#ifdef _WIN32
    int ret = system("g++ -std=c++11 main.cpp -o main.exe");
#else
    int ret = system("g++ -std=c++11 main.cpp -o main");
#endif
    return ret == 0;
}

// Функция запуска main и получения результата
string runMain(const string &input) {
    const char* inputFile = "temp_input.txt";
    const char* outputFile = "temp_output.txt";

    // Записываем входные данные во временный файл
    ofstream fin(inputFile);
    fin << input;
    fin.close();

    // Запускаем main
#ifdef _WIN32
    system("main.exe < temp_input.txt > temp_output.txt");
#else
    system("./main < temp_input.txt > temp_output.txt");
#endif

    // Читаем результат из файла
    ifstream fout(outputFile);
    string result;
    getline(fout, result);
    fout.close();

    return result;
}

int main() {
    // Компилируем main.cpp
    if (!compileMain()) {
        cout << "Ошибка компиляции main.cpp\n";
        return 1;
    }

    vector<TestCase> tests = {
        {"ABBACAB\nABAC\n", "4"},
        {"A\nA\n", "0"},
        {"ABC\nDEF\n", "0"},
        {"ABABAB\nBABA\n", "3"},
        {"AAAA\nAAA\n", "3"},
        {"ABCDE\nABCDE\n", "4"},
        {"XYZ\nXY\n", "1"},
        {"ABCDEF\nBCDEFA\n", "5"},
        {"AAAAA\nAAA\n", "4"},
        {"ABCD\nABCD\n", "3"}
    };

    int passed = 0;

    for (size_t i = 0; i < tests.size(); ++i) {
        string output = runMain(tests[i].input);

        cout << "Тест #" << (i + 1) << ": ";
        if (output == tests[i].expected) {
            cout << "✔ Пройден\n";
            ++passed;
        } else {
            cout << "✗ Ошибка\n";
            cout << "  Ожидалось: " << tests[i].expected << "\n";
            cout << "  Получено:   " << output << "\n";
        }
    }

    cout << "\n=== ИТОГ ===\nПройдено тестов: " << passed << " из " << tests.size() << "\n";
    return 0;
}
