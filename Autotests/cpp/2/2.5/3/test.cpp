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

    // Тест 1: обычный сдвиг
    string input1 = "5 2\n1 2 3 4 5\n";
    string expected1 = "3 4 5 1 2 ";
    if (run_test(input1, expected1)) passed++;

    // Тест 2: k = 0 (ничего не меняется)
    string input2 = "4 0\n10 20 30 40\n";
    string expected2 = "10 20 30 40 ";
    if (run_test(input2, expected2)) passed++;

    // Тест 3: k > n (эквивалентно k % n)
    string input3 = "4 6\n10 20 30 40\n";
    string expected3 = "30 40 10 20 ";
    if (run_test(input3, expected3)) passed++;

    // Тест 4: n = 1
    string input4 = "1 100\n42\n";
    string expected4 = "42 ";
    if (run_test(input4, expected4)) passed++;

    cout << "Пройдено " << passed << " тестов из 4" << endl;
    return 0;
}
