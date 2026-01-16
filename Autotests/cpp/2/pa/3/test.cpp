#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

struct Test {
    vector<int> input;
    string expected;
};

void writeInput(const vector<int>& v) {
    ofstream in("input.txt");
    for (int x : v) in << x << " ";
}

string readOutput() {
    ifstream out("output.txt");
    string s, line;
    while (getline(out, line)) {
        if (!s.empty()) s += "\n";
        s += line;
    }
    return s;
}

int main() {
    cout << "== Компиляция main.cpp ==\n";

#ifdef _WIN32
    int compile = system("g++ -std=c++11 -w main.cpp -o main.exe");
    const char* run = "main.exe";
#else
    int compile = system("g++ -std=c++11 -w main.cpp -o main.out");
    const char* run = "./main.out";
#endif

    if (compile != 0) {
        cout << "❌ Ошибка компиляции main.cpp\n";
        return 1;
    }

    vector<Test> tests = {
        {{3,1,4,5,2}, "1 2 3 4 5"},
        {{1,2,3,4,5}, "1 2 3 4 5"},
        {{5,4,3,2,1}, "1 2 3 4 5"},
        {{7,7,7,7},   "7 7 7 7"},
        {{-3,0,2,-1,4}, "-3 -1 0 2 4"}
    };

    bool ok = true;

    for (size_t i = 0; i < tests.size(); ++i) {
        writeInput(tests[i].input);
        system(run);

        string out = readOutput();
        if (out != tests[i].expected) {
            ok = false;
            cout << "❌ Тест " << i + 1 << " не пройден\n";
            cout << "Ожидалось: " << tests[i].expected << "\n";
            cout << "Получено : " << out << "\n\n";
        } else {
            cout << "✅ Тест " << i + 1 << " пройден\n";
        }
    }

    if (ok)
        cout << "\n🎉 Все тесты успешно пройдены\n";

    return 0;
}
