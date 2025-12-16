#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  // для system()
using namespace std;

// Функция для запуска теста
bool run_test(const string& input, const string& expected_output, int test_number) {
    // Сохраняем входные данные в input.txt
    ofstream infile("input.txt");
    infile << input;
    infile.close();

    // Запускаем main.cpp, вывод в output.txt
    int compile_res = system("g++ -std=c++11 main.cpp -o main");
    if (compile_res != 0) {
        cout << "Ошибка компиляции main.cpp" << endl;
        return false;
    }

    int run_res = system("./main < input.txt > output.txt");
    if (run_res != 0) {
        cout << "Ошибка выполнения main" << endl;
        return false;
    }

    // Читаем результат из output.txt
    ifstream outfile("output.txt");
    string output((istreambuf_iterator<char>(outfile)), istreambuf_iterator<char>());
    outfile.close();

    // Убираем возможные переносы строк в конце
    while (!output.empty() && (output.back() == '\n' || output.back() == '\r'))
        output.pop_back();

    string expected = expected_output;
    while (!expected.empty() && (expected.back() == '\n' || expected.back() == '\r'))
        expected.pop_back();

    if (output == expected) {
        cout << "Тест #" << test_number << ": ✔ Пройден" << endl;
        return true;
    } else {
        cout << "Тест #" << test_number << ": ✗ Ошибка" << endl;
        cout << "  Ожидалось:\n" << expected << endl;
        cout << "  Получено:\n" << output << endl;
        return false;
    }
}

int main() {
    int passed = 0;
    int total = 5;

    // Тестовые данные: input, expected_output
    string tests_input[] = {
        "5\n1 3 3 2 1\n",
        "6\n1 2 3 2 1 0\n",
        "3\n1 2 1\n",
        "4\n5 5 5 5\n",
        "7\n1 2 2 2 1 3 2\n"
    };
    string tests_expected[] = {
        "4\n1 3\n",
        "3\n2 4\n",
        "3\n1 3\n",
        "0\n",
        "4\n2 4\n"
    };

    for (int i = 0; i < total; ++i) {
        if (run_test(tests_input[i], tests_expected[i], i+1)) passed++;
    }

    cout << "\n=== ИТОГ ===" << endl;
    cout << "Пройдено тестов: " << passed << " из " << total << endl;

    return 0;
}
