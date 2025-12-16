#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

bool run_test(const string& input, const string& expected) {
    ofstream infile("input.txt");
    infile << input;
    infile.close();

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
    string output, line;
    string result;
    while (getline(outfile, line)) {
        // Убираем лишний пробел в конце строки
        if (!line.empty() && line.back() == ' ') line.pop_back();
        result += line + "\n";
    }
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

    // Тест 1: 3x3 матрица
    string input1 = "3 3\n";
    string expected1 = "1 2 3\n8 9 4\n7 6 5\n";
    if (run_test(input1, expected1)) passed++;

    // Тест 2: 4x3 матрица
    string input2 = "4 3\n";
    string expected2 = "1 2 3\n10 11 4\n9 12 5\n8 7 6\n";
    if (run_test(input2, expected2)) passed++;

    // Тест 3: 2x5 матрица
    string input3 = "2 5\n";
    string expected3 = "1 2 3 4 5\n10 9 8 7 6\n";
    if (run_test(input3, expected3)) passed++;

    cout << "Пройдено " << passed << " тестов из 3" << endl;
    return 0;
}
