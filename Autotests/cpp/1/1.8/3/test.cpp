#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

// Функция для запуска main.cpp с подачей input
string run_main(const string& input) {
    // записываем ввод
    ofstream fin("input.txt");
    fin << input;
    fin.close();

    // компилируем main.cpp
    system("g++ -std=c++11 -w main.cpp -o main.out");

    // запускаем main.out
    system("./main.out < input.txt > output.txt");

    // читаем результат
    ifstream fout("output.txt");
    string res;
    fout >> res;
    fout.close();
    return res;
}

// Проверка одного теста
void test_case(int id, const string& input, const string& expected) {
    string got = run_main(input);

    cout << "Тест #" << id << ": ";
    if (got == expected) {
        cout << "✔ Пройден\n";
    } else {
        cout << "✗ Ошибка\n";
        cout << "   Ожидалось: " << expected << "\n";
        cout << "   Получено:  " << got << "\n";
    }
}

int main() {
    cout << "=== ТЕСТИРОВАНИЕ ЗАДАЧИ 'ЧИСЛА ФИБОНАЧЧИ' ===\n\n";

    // Тесты
    test_case(1, "0\n", "0"); // a0 = 0
    test_case(2, "1\n", "1"); // a1 = 1
    test_case(3, "2\n", "1"); // a2 = 1
    test_case(4, "5\n", "5"); // a5 = 5
    test_case(5, "7\n", "13"); // a7 = 13
    test_case(6, "10\n", "55"); // a10 = 55
    test_case(7, "30\n", "832040"); // a30 = 832040

    cout << "\n=== Тестирование завершено ===\n";
    return 0;
}
