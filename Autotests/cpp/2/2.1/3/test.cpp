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

// читаем тесты из файла, разделённые пустой строкой
vector<TestCase> readTests(const string &filename) {
    ifstream fin(filename);
    vector<TestCase> tests;
    string line, inputBlock, expected;

    vector<string> lines;
    while (getline(fin, line)) {
        if (line.empty()) {
            if (!lines.empty()) {
                expected = lines.back();
                lines.pop_back();
                inputBlock = "";
                for (auto &l : lines) inputBlock += l + "\n";
                tests.push_back({inputBlock, expected});
                lines.clear();
            }
        } else {
            lines.push_back(line);
        }
    }

    if (!lines.empty()) {
        expected = lines.back();
        lines.pop_back();
        inputBlock = "";
        for (auto &l : lines) inputBlock += l + "\n";
        tests.push_back({inputBlock, expected});
    }

    return tests;
}

int main() {
    string studentFile = "main.cpp";
    string studentExe = "main.out";

    cout << "Компиляция " << studentFile << "..." << endl;
    if (system(("g++ " + studentFile + " -o " + studentExe + " -std=c++11 2> compile.log").c_str()) != 0) {
        cout << "❌ Ошибка компиляции! Смотри compile.log" << endl;
        return 1;
    }

    vector<TestCase> tests = readTests("tests.txt");
    if (tests.empty()) {
        cout << "❌ Файл tests.txt пуст или не найден!" << endl;
        return 1;
    }

    bool allPassed = true;

    for (size_t i = 0; i < tests.size(); i++) {
        ofstream fin("input.txt");
        fin << tests[i].input;
        fin.close();

#ifdef _WIN32
        system((studentExe + " < input.txt > output.txt").c_str());
#else
        system(("./" + studentExe + " < input.txt > output.txt").c_str());
#endif

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
