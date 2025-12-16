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

    // Тест 1: простое сложение
    string input1 = "2+3";
    string expected1 = "+23";
    if (run_test(input1, expected1)) passed++;

    // Тест 2: сложение и умножение
    string input2 = "2+3*4";
    string expected2 = "+2*34";
    if (run_test(input2, expected2)) passed++;

    // Тест 3: скобки
    string input3 = "(2+3)*4";
    string expected3 = "*+234";
    if (run_test(input3, expected3)) passed++;

    // Тест 4: более сложное выражение
    string input4 = "5*(6+7)-8";
    string expected4 = "-*5+678";
    if (run_test(input4, expected4)) passed++;

    // Тест 5: один операнд
    string input5 = "9";
    string expected5 = "9";
    if (run_test(input5, expected5)) passed++;

    cout << "Пройдено " << passed << " тестов из 5" << endl;
    return 0;
}
