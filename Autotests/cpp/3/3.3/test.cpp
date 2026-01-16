#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

// Функция запуска теста
bool run_test(const string& input, const string& expected) {
    // Записываем входные данные
    ofstream fin("input.txt");
    fin << input;
    fin.close();

#ifdef _WIN32
    // Компиляция main.cpp
    if (system("g++ -std=c++11 -w main.cpp -o main.exe") != 0) return false;
    // Запуск
    system("main.exe < input.txt > output.txt");
#else
    if (system("g++ -std=c++11 -w main.cpp -o main.out") != 0) return false;
    system("./main.out < input.txt > output.txt");
#endif

    // Считываем вывод
    ifstream fout("output.txt");
    string output, line;
    while (getline(fout, line)) output += line + "\n";
    fout.close();

    return output == expected;
}

int main() {
    int passed = 0;
    int total = 1;

    // Тест 1: n = 3
    string input = "3\n";
    string expected =
        "Method 1: Nested loops\n"
        "1\t2\t3\t\n"
        "2\t4\t6\t\n"
        "3\t6\t9\t\n"
        "\n"
        "Method 2: One-dimensional array\n"
        "1\t2\t3\t\n"
        "2\t4\t6\t\n"
        "3\t6\t9\t\n";

    if (run_test(input, expected)) {
        cout << "Test passed\n";
        passed++;
    } else {
        cout << "Test failed\n";
    }

    cout << "Passed " << passed << " out of " << total << " tests\n";
    return 0;
}
