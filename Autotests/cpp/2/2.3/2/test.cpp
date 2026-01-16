#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

bool run_test(const string& input, const string& expected) {
    // Записываем входные данные во временный файл
    ofstream infile("input.txt");
    infile << input;
    infile.close();

    // Компилируем main.cpp с C++11 и подавлением предупреждений
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

    // Исправленные тесты
    if (run_test("5\n1 3 -2 4 2\n", "10 0")) passed++;
    if (run_test("4\n-1 -2 -3 -4\n", "0 6")) passed++;
    if (run_test("6\n1 2 3 4 5 6\n", "21 120")) passed++;

    cout << "Пройдено " << passed << " тестов из 3" << endl;
    return 0;
}
