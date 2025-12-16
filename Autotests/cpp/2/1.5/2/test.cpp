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

    // Тест 1: добавление и выполнение одной задачи
    string input1 = "3\nADD task1\nSIZE\nRUN\n";
    string expected1 = "1\ntask1";
    if (run_test(input1, expected1)) passed++;

    // Тест 2: RUN при пустой очереди
    string input2 = "1\nRUN\n";
    string expected2 = "IDLE";
    if (run_test(input2, expected2)) passed++;

    // Тест 3: несколько задач
    string input3 = "5\nADD build\nADD test\nSIZE\nRUN\nRUN\n";
    string expected3 = "2\nbuild\ntest";
    if (run_test(input3, expected3)) passed++;

    // Тест 4: очередность задач
    string input4 = "6\nADD first\nADD second\nRUN\nADD third\nRUN\nRUN\n";
    string expected4 = "first\nsecond\nthird";
    if (run_test(input4, expected4)) passed++;

    cout << "Пройдено " << passed << " тестов из 4" << endl;
    return 0;
}
