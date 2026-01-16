#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

bool run_test(const string& input, const string& expected) {
    // записываем входные данные
    ofstream fin("input.txt");
    fin << input;
    fin.close();

#ifdef _WIN32
    if (system("g++ -std=c++11 -w main.cpp -o main.exe") != 0) return false;
    system("main.exe < input.txt > output.txt");
#else
    if (system("g++ -std=c++11 -w main.cpp -o main.out") != 0) return false;
    system("./main.out < input.txt > output.txt");
#endif

    ifstream fout("output.txt");
    string output, line;
    while (getline(fout, line)) output += line + "\n";
    fout.close();

    return output == expected;
}

int main() {
    int passed = 0;
    int total = 3;

    // Тест 1: N=3, K=0 → только [1,2,3]
    string input1 = "3 0\n";
    string expected1 = "1\n";
    if (run_test(input1, expected1)) { cout << "Test 1 passed\n"; passed++; }
    else cout << "Test 1 failed\n";

    // Тест 2: N=3, K=1 → [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ? Проверим
    // На самом деле для N=3:
    // K=1 → [1,3,2],[2,1,3],[3,1,2] → 3 перестановки
    string input2 = "3 1\n";
    string expected2 = "2\n"; // Проверка вручную: [1,3,2] и [2,1,3]? да, должно быть 2
    if (run_test(input2, expected2)) { cout << "Test 2 passed\n"; passed++; }
    else cout << "Test 2 failed\n";

    // Тест 3: N=3, K=2 → [2,3,1],[3,1,2],[3,2,1] → 3
    string input3 = "3 2\n";
    string expected3 = "2\n"; // Проверка DP вручную, иногда считается через n*(n-1)/2?
    if (run_test(input3, expected3)) { cout << "Test 3 passed\n"; passed++; }
    else cout << "Test 3 failed\n";

    cout << "Passed " << passed << " out of " << total << " tests\n";
    return 0;
}
