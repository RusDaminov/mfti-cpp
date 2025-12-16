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

    // Тест 1: базовые операции
    string input1 =
        "6\n"
        "PUSH 10\n"
        "FRONT\n"
        "PUSH 20\n"
        "SIZE\n"
        "POP\n"
        "FRONT\n";
    string expected1 =
        "10\n"
        "2\n"
        "20\n";
    if (run_test(input1, expected1)) passed++;

    // Тест 2: пустая очередь
    string input2 =
        "4\n"
        "FRONT\n"
        "POP\n"
        "SIZE\n"
        "FRONT\n";
    string expected2 =
        "EMPTY\n"
        "EMPTY\n"
        "0\n"
        "EMPTY\n";
    if (run_test(input2, expected2)) passed++;

    // Тест 3: несколько элементов
    string input3 =
        "7\n"
        "PUSH 1\n"
        "PUSH 2\n"
        "PUSH 3\n"
        "FRONT\n"
        "POP\n"
        "FRONT\n"
        "SIZE\n";
    string expected3 =
        "1\n"
        "2\n"
        "2\n";
    if (run_test(input3, expected3)) passed++;

    cout << "Пройдено " << passed << " тестов из 3" << endl;
    return 0;
}
