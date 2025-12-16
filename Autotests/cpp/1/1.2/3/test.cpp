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
    while (getline(outfile, line)) {
        if (!output.empty()) output += "\n";
        output += line;
    }
    outfile.close();

    if (output == expected) {
        cout << "Тест пройден ✅" << endl;
        return true;
    } else {
        cout << "Тест провален ❌" << endl;
        cout << "Ожидалось:\n" << expected << endl;
        cout << "Получено:\n" << output << endl;
        return false;
    }
}

int main() {
    int passed = 0;

    // Тест 1: обычные положительные числа и true
    string input1 = "42\n3.1415\n1\n";
    string expected1 =
        "Введите целое число: Введите вещественное число: Введите логическое значение (0/1): "
        "Целое: 42\nВещественное: 3.14\nЛогическое: true";
    if (run_test(input1, expected1)) passed++;

    // Тест 2: отрицательное целое, число с двумя знаками после запятой и false
    string input2 = "-7\n2.5\n0\n";
    string expected2 =
        "Введите целое число: Введите вещественное число: Введите логическое значение (0/1): "
        "Целое: -7\nВещественное: 2.50\nЛогическое: false";
    if (run_test(input2, expected2)) passed++;

    cout << "Пройдено " << passed << " тестов из 2" << endl;
    return 0;
}
