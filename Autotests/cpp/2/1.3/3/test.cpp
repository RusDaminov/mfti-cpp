#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

bool run_test(const string& input, const string& expected) {
    ofstream infile("input.txt");
    infile << input;
    infile.close();

    // Компиляция с C++11
    int compile_status = system("g++ -std=c++11 main.cpp -o student_program -w");
    if (compile_status != 0) {
        cerr << "Ошибка компиляции!" << endl;
        return false;
    }

    int run_status = system("./student_program < input.txt > output.txt");
    if (run_status != 0) {
        cerr << "Ошибка при выполнении программы!" << endl;
        return false;
    }

    ifstream outfile("output.txt");
    string output, line, expected_line;
    string result;
    while (getline(outfile, line)) result += line + "\n";
    outfile.close();

    if (result == expected) {
        cout << "Тест пройден ✅" << endl;
        return true;
    } else {
        cout << "Тест провален ❌" << endl;
        cout << "Ожидалось:\n" << expected;
        cout << "Получено:\n" << result;
        return false;
    }
}

int main() {
    int passed = 0;

    // Пример теста 1 (3x3 матрица)
    string input1 = "3\n1 2 3\n4 5 6\n7 8 9\n";
    string expected1 = "0 2 0\n4 0 6\n0 8 0\n";
    if (run_test(input1, expected1)) passed++;

    // Пример теста 2 (4x4 матрица)
    string input2 = "4\n1 2 3 4\n5 6 7 8\n9 10 11 12\n13 14 15 16\n";
    string expected2 = "0 2 3 0\n5 0 0 8\n9 0 0 12\n0 14 15 0\n";
    if (run_test(input2, expected2)) passed++;

    cout << "Пройдено " << passed << " тестов из 2" << endl;
    return 0;
}
