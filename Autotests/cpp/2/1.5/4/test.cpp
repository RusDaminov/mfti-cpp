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

    // Тест 1: простая цепочка
    string input1 = "4 3\n1 2\n2 3\n3 4\n";
    string expected1 = "3";
    if (run_test(input1, expected1)) passed++;

    // Тест 2: прямое ребро от 1 к n
    string input2 = "3 1\n1 3\n";
    string expected2 = "1";
    if (run_test(input2, expected2)) passed++;

    // Тест 3: граф несвязный (пути нет)
    string input3 = "4 2\n1 2\n3 4\n";
    string expected3 = "-1";
    if (run_test(input3, expected3)) passed++;

    // Тест 4: полный граф (все вершины связаны)
    string input4 = "4 6\n1 2\n1 3\n1 4\n2 3\n2 4\n3 4\n";
    string expected4 = "1";
    if (run_test(input4, expected4)) passed++;

    cout << "Пройдено " << passed << " тестов из 4" << endl;
    return 0;
}
