#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

#ifdef _WIN32
    const string exeName = "main.exe";
#else
    const string exeName = "main";
#endif

struct TestCase {
    string input;
    string expected;
    string comment;
};

string runProgram(const string& input) {
    ofstream fin("input.txt");
    fin << input;
    fin.close();

    string compileCmd = "g++ -std=c++11 -w main.cpp -o " + exeName;
    if (system(compileCmd.c_str()) != 0) {
        cerr << "❌ Ошибка компиляции main.cpp" << endl;
        exit(1);
    }

#ifdef _WIN32
    string runCmd = exeName + " < input.txt > output.txt";
#else
    string runCmd = "./" + exeName + " < input.txt > output.txt";
#endif
    system(runCmd.c_str());

    ifstream fout("output.txt");
    stringstream buffer;
    buffer << fout.rdbuf();
    string output = buffer.str();

    // Удаляем все фразы вроде "Введите N:", "Ответ:" и пробелы
    vector<string> wordsToRemove = {"Введите", "N", "K", "Ответ", ":", " "};
    for (auto &word : wordsToRemove) {
        size_t pos;
        while ((pos = output.find(word)) != string::npos)
            output.erase(pos, word.length());
    }

    // Убираем переводы строк
    output.erase(remove(output.begin(), output.end(), '\n'), output.end());
    output.erase(remove(output.begin(), output.end(), '\r'), output.end());

    return output;
}

int main() {
    vector<TestCase> tests = {
        {"10\n2\n", "4", "2+3+4+5=14 → 4 дня"},
        {"10\n3\n", "3", "3+4+5=12 → 3 дня"},
        {"5\n5\n", "1", "Решил всё за 1 день"},
        {"15\n1\n", "5", "1+2+3+4+5=15 → 5 дней"},
        {"100\n10\n", "8", "10+11+12+13+14+15+16+17=108 → 8 дней"}
    };

    cout << "=== ТЕСТИРОВАНИЕ ЗАДАЧИ «ЮРА ГОТОВИТСЯ К ОЛИМПИАДЕ» ===" << endl;

    int passed = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        cout << "\nТест #" << (i + 1) << ": " << tests[i].comment << endl;

        string result = runProgram(tests[i].input);

        if (result == tests[i].expected) {
            cout << "✅ Пройден. Вывод: " << result << endl;
            passed++;
        } else {
            cout << "❌ Провален." << endl;
            cout << "   Ожидалось: \"" << tests[i].expected << "\"" << endl;
            cout << "   Получено:   \"" << result << "\"" << endl;
        }
    }

    cout << "\n==============================" << endl;
    cout << "Пройдено тестов: " << passed << " из " << tests.size() << endl;
    cout << "==============================" << endl;

    return 0;
}
