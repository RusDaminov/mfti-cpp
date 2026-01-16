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
        if (!line.empty() && line.back() == ' ') line.pop_back(); // убираем пробел в конце
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

    // Тест 1: 3x3
    string input1 = "3 3\n";
    string expected1 = "1 2 3\n6 5 4\n7 8 9\n";
    if (run_test(input1, expected1)) passed++;

    // Тест 2: 4x5
    string input2 = "4 5\n";
    string expected2 = "1 2 3 4 5\n10 9 8 7 6\n11 12 13 14 15\n20 19 18 17 16\n";
    if (run_test(input2, expected2)) passed++;

    // Тест 3: 2x4
    string input3 = "2 4\n";
    string expected3 = "1 2 3 4\n8 7 6 5\n";
    if (run_test(input3, expected3)) passed++;

    cout << "Пройдено " << passed << " тестов из 3" << endl;
    return 0;
}
