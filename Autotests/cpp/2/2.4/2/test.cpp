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
    string output;
    getline(outfile, output);
    outfile.close();

    if (output == expected) {
        cout << "Тест пройден ✅" << endl;
        return true;
    } else {
        cout << "Тест провален ❌" << endl;
        cout << "Ожидалось: " << expected << endl;
        cout << "Получено:  " << output << endl;
        return false;
    }
}

int main() {
    int passed = 0;

    // Тест 1: корректная последовательность
    string input1 = "()[]{}";
    string expected1 = "YES";
    if (run_test(input1, expected1)) passed++;

    // Тест 2: некорректная последовательность
    string input2 = "([)]";
    string expected2 = "NO";
    if (run_test(input2, expected2)) passed++;

    // Тест 3: вложенные скобки
    string input3 = "{[()]}";
    string expected3 = "YES";
    if (run_test(input3, expected3)) passed++;

    // Тест 4: пустая строка
    string input4 = "";
    string expected4 = "YES";
    if (run_test(input4, expected4)) passed++;

    // Тест 5: лишняя открывающая скобка
    string input5 = "(((";
    string expected5 = "NO";
    if (run_test(input5, expected5)) passed++;

    cout << "Пройдено " << passed << " тестов из 5" << endl;
    return 0;
}
