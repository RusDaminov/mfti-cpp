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
    string input1 = "2 3 +";
    string expected1 = "5";
    if (run_test(input1, expected1)) passed++;

    // Тест 2: несколько операций
    string input2 = "2 3 4 * +";
    string expected2 = "14"; // 2 + (3*4)
    if (run_test(input2, expected2)) passed++;

    // Тест 3: вычитание
    string input3 = "10 4 -";
    string expected3 = "6";
    if (run_test(input3, expected3)) passed++;

    // Тест 4: сложное выражение
    string input4 = "5 6 7 + * 8 -";
    string expected4 = "57"; // 5*(6+7)-8 = 65-8
    if (run_test(input4, expected4)) passed++;

    // Тест 5: деление
    string input5 = "20 5 /";
    string expected5 = "4";
    if (run_test(input5, expected5)) passed++;

    // Тест 6: многозначные числа
    string input6 = "100 20 /";
    string expected6 = "5";
    if (run_test(input6, expected6)) passed++;

    // Тест 7: отрицательный результат
    string input7 = "3 7 -";
    string expected7 = "-4";
    if (run_test(input7, expected7)) passed++;

    // Тест 8: комбинированное выражение
    string input8 = "15 7 1 1 + - / 3 * 2 1 1 + + -";
    string expected8 = "5"; // знаменитый пример RPN из Википедии
    if (run_test(input8, expected8)) passed++;

    cout << "Пройдено " << passed << " тестов из 8" << endl;
    return 0;
}
