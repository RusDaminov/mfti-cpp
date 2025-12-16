#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cctype>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

// функция для удаления лишних пробелов и переносов строк
string trimSpaces(const string &s) {
    string result;
    bool space = false;
    for (char c : s) {
        if (isspace(c)) {
            if (!space) result += ' ';
            space = true;
        } else {
            result += c;
            space = false;
        }
    }
    if (!result.empty() && result.front() == ' ') result.erase(result.begin());
    if (!result.empty() && result.back() == ' ') result.pop_back();
    return result;
}

int main() {
    string studentFile = "main.cpp"; // файл студента
    string studentExe = "main.out";

    // 1️⃣ Компиляция
    cout << "Компиляция " << studentFile << "..." << endl;
    if (system(("g++ " + studentFile + " -o " + studentExe + " -std=c++11 2> compile.log").c_str()) != 0) {
        cout << "❌ Ошибка компиляции! Смотри compile.log" << endl;
        return 1;
    }

    // 2️⃣ Тесты
    vector<TestCase> tests;
    tests.push_back({"10\n", "2 3 5 7"});
    tests.push_back({"1\n", ""});
    tests.push_back({"2\n", "2"});
    tests.push_back({"20\n", "2 3 5 7 11 13 17 19"});
    tests.push_back({"30\n", "2 3 5 7 11 13 17 19 23 29"});

    bool allPassed = true;

    // 3️⃣ Прогон тестов
    for (size_t i = 0; i < tests.size(); i++) {
        // записываем вход в файл
        ofstream fin("input.txt");
        fin << tests[i].input;
        fin.close();

        // запускаем программу студента
        #ifdef _WIN32
        system((studentExe + " < input.txt > output.txt").c_str());
        #else
        system(("./" + studentExe + " < input.txt > output.txt").c_str());
        #endif

        // читаем вывод
        ifstream fout("output.txt");
        stringstream buffer;
        buffer << fout.rdbuf();
        string output = buffer.str();
        fout.close();

        string studentAnswer = trimSpaces(output);
        string expectedAnswer = trimSpaces(tests[i].expected);

        cout << "Тест " << i + 1 << ": ";
        if (studentAnswer == expectedAnswer) {
            cout << "✅ Пройден" << endl;
        } else {
            cout << "❌ Ошибка.\n   Ожидалось: \"" << expectedAnswer 
                 << "\"\n   Получено: \"" << studentAnswer << "\"" << endl;
            allPassed = false;
        }
    }

    if (allPassed) {
        cout << "\n🎉 Все тесты пройдены!" << endl;
    } else {
        cout << "\n⚠️ Есть ошибки в решении" << endl;
    }

    return 0;
}
