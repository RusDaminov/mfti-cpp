#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct TestCase {
    string input;
    long long K;
    bool hasPair; // ожидается ли пара
};

int main() {
    vector<TestCase> tests = {
        {"5 7\n1 2 3 4 5\n", 7, true},
        {"4 8\n1 3 5 7\n", 8, false},
        {"6 10\n2 4 6 8 5 5\n", 10, true},
        {"3 4\n2 2 2\n", 4, true},
        {"2 10\n6 4\n", 10, true}
    };

    int passed = 0;
    int total = tests.size();

    // Компиляция main.cpp
    if (system("g++ -std=c++11 -w main.cpp -o main") != 0) {
        cerr << "Ошибка компиляции main.cpp" << endl;
        return 1;
    }

    for (size_t i = 0; i < tests.size(); ++i) {
        ofstream input("input.txt");
        input << tests[i].input;
        input.close();

        system("./main < input.txt > output.txt");

        ifstream output("output.txt");
        string line;
        getline(output, line);
        output.close();

        if (line == "-1") {
            if (!tests[i].hasPair) {
                cout << "Тест " << i + 1 << " пройден ✅ (нет пары)" << endl;
                passed++;
            } else {
                cout << "Тест " << i + 1 << " провален ❌ (ожидалась пара)" << endl;
            }
        } else {
            istringstream iss(line);
            int idx1, idx2;
            iss >> idx1 >> idx2;

            // Считываем массив для проверки
            istringstream inputCheck(tests[i].input);
            int N;
            long long K;
            inputCheck >> N >> K;
            vector<long long> A(N);
            for (int j = 0; j < N; ++j) inputCheck >> A[j];

            // Проверяем корректность индексов и суммы
            if (1 <= idx1 && idx1 <= N && 1 <= idx2 && idx2 <= N && idx1 != idx2 &&
                A[idx1 - 1] + A[idx2 - 1] == tests[i].K) {
                cout << "Тест " << i + 1 << " пройден ✅" << endl;
                passed++;
            } else {
                cout << "Тест " << i + 1 << " провален ❌" << endl;
                cout << "Вывод программы: " << line << endl;
            }
        }
    }

    cout << "\nРезультат: " << passed << "/" << total << " тестов успешно.\n";
    return 0;
}
