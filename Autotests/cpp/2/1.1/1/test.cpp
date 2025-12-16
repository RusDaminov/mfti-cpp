#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

// сравнение вещественных чисел
bool almostEqual(double a, double b, double eps = 1e-4) {
    return fabs(a - b) < eps;
}

struct TestCase {
    string input;
    string expected;
};

int main() {
    string studentFile = "main.cpp";

    // 1. Компилируем код студента
    cout << "🔨 Компиляция main.cpp..." << endl;
    if (system(("g++ " + studentFile + " -o main.out 2> compile.log").c_str()) != 0) {
        cout << "❌ Ошибка компиляции! Смотри compile.log" << endl;
        return 1;
    }

    // 2. Готовим тесты
    vector<TestCase> tests = {
        {"2 -4 0 5 0.001\n", "2.0000\n"},               // x = -b/a = 2, входит в [0,5]
        {"2 -4 3 5 0.001\n", "No root on segment\n"},   // x = 2, но отрезок [3,5]
        {"1 -1 0 2 0.01\n", "1.0000\n"},                // x = 1, в [0,2]
        {"3 6 -10 -1 0.001\n", "-2.0000\n"},            // x = -2, в [-10,-1]
        {"5 10 0 1 0.001\n", "No root on segment\n"}    // x = -2, не входит
    };

    bool allPassed = true;

    // 3. Прогоняем тесты
    for (size_t i = 0; i < tests.size(); i++) {
        // записываем вход
        ofstream fin("input.txt");
        fin << tests[i].input;
        fin.close();

        // запускаем студента
        system("./main.out < input.txt > output.txt");

        // читаем вывод
        ifstream fout("output.txt");
        string output;
        getline(fout, output);
        fout.close();

        cout << "Тест " << i + 1 << ": ";
        if (tests[i].expected == "No root on segment\n") {
            if (output == "No root on segment") {
                cout << "✅ Пройден" << endl;
            } else {
                cout << "❌ Ошибка. Ожидалось: " << tests[i].expected
                     << " Получено: " << output << endl;
                allPassed = false;
            }
        } else {
            // проверяем число
            double expectedValue, studentValue;
            stringstream ss1(tests[i].expected), ss2(output);
            ss1 >> expectedValue;
            ss2 >> studentValue;

            if (almostEqual(expectedValue, studentValue)) {
                cout << "✅ Пройден" << endl;
            } else {
                cout << "❌ Ошибка. Ожидалось: " << expectedValue
                     << ", получено: " << studentValue << endl;
                allPassed = false;
            }
        }
    }

    if (allPassed) {
        cout << "\n🎉 Все тесты пройдены!" << endl;
    } else {
        cout << "\n⚠️ Некоторые тесты не пройдены" << endl;
    }

    return 0;
}
