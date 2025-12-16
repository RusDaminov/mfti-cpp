#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // для system
using namespace std;

bool run_test(const string& input, const string& expected) {
    // Записываем входные данные во временный файл
    ofstream infile("input.txt");
    infile << input;
    infile.close();

    // Компилируем main.cpp студента с C++11 и подавляем предупреждения
    int compile_status = system("g++ -std=c++11 main.cpp -o student_program -w");
    if (compile_status != 0) {
        cerr << "Ошибка компиляции!" << endl;
        return false;
    }

    // Запускаем программу студента и перенаправляем вывод в файл
    int run_status = system("./student_program < input.txt > output.txt");
    if (run_status != 0) {
        cerr << "Ошибка при выполнении программы!" << endl;
        return false;
    }

    // Читаем вывод программы
    ifstream outfile("output.txt");
    string output;
    getline(outfile, output);
    outfile.close();

    // Сравниваем с ожидаемым
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

    // Примеры тестов
    if (run_test("5\n1 3 5 2 4\n", "1 5")) passed++;
    if (run_test("3\n10 10 10\n", "10 10")) passed++;
    if (run_test("4\n-1 -2 -3 -4\n", "-4 -1")) passed++;

    cout << "Пройдено " << passed << " тестов из 3" << endl;
    return 0;
}
