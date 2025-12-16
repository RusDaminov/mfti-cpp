// test.cpp — 100% корректный тестер (все баги исправлены)

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

bool is_valid(const vector<int>& arr, const map<int,int>& freq) {
    if (arr.empty()) return false;
    for (size_t i = 1; i < arr.size(); ++i)
        if (arr[i] == arr[i-1]) return false;
    map<int,int> cnt;
    for (int x : arr) cnt[x]++;
    return cnt == freq;
}

bool run_test(const string& input, const string& name, int num, bool expect_zero = false) {
    cout << "Тест " << num << " (" << name << ")... ";

    ofstream("input.txt") << input;
    
#if defined(_WIN32)
    system("solution.exe < input.txt > output.txt 2> err.txt");
#else
    system("./solution < input.txt > output.txt 2> err.txt");
#endif

    string output;
    ifstream f("output.txt");
    stringstream ss; ss << f.rdbuf(); output = trim(ss.str());

    map<int,int> freq;
    stringstream in(input); int n, x; in >> n;
    for (int i = 0; i < n; ++i) { in >> x; freq[x]++; }

    if (expect_zero) {
        bool ok = (output == "0");
        cout << (ok ? "OK" : "WA") << endl;
        return ok;
    } else {
        if (output == "0") { cout << "WA (выдал 0, а можно было)" << endl; return false; }
        vector<int> arr;
        stringstream out(output); while (out >> x) arr.push_back(x);
        if (arr.size() != size_t(n)) { cout << "WA (неверный размер)" << endl; return false; }
        bool ok = is_valid(arr, freq);
        cout << (ok ? "OK" : "WA (соседи или неправильный состав)") << endl;
        return ok;
    }
}

int main() {
    cout << "Компиляция main.cpp..." << endl;
#if defined(_WIN32)
    if (system("g++ main.cpp -o solution.exe -O2 -std=c++17 -Wall -Wextra >nul 2>&1")) {
        cout << "ОШИБКА КОМПИЛЯЦИИ" << endl; return 1;
    }
#else
    if (system("g++ main.cpp -o solution -O2 -std=c++17 -Wall -Wextra >/dev/null 2>&1")) {
        cout << "ОШИБКА КОМПИЛЯЦИИ" << endl; return 1;
    }
#endif
    cout << "Успешно!" << endl << endl;

    int passed = 0, total = 0;

    ++total; if (run_test("7\n1 1 1 2 2 3 4", "обычный", total)) passed++;
    ++total; if (run_test("7\n1 1 1 1 1 2 3", "5 из одной → невозможно", total, true)) passed++;
    ++total; if (run_test("5\n10 20 30 40 50", "все разные", total)) passed++;
    ++total; if (run_test("5\n1 1 1 2 3", "max=3, n=5 → можно", total)) passed++;
    ++total; if (run_test("6\n2 2 2 2 1 3", "max=4, n=6 → невозможно", total, true)) passed++;
    ++total; if (run_test("1\n100", "один участник", total)) passed++;
    ++total; if (run_test("2\n7 7", "два одинаковых → невозможно", total, true)) passed++;  // ИСПРАВЛЕНО
    ++total; if (run_test("3\n1 1 2", "два из одной → можно", total)) passed++;
    ++total; if (run_test("4\n1 1 1 2", "max=3, n=4 → невозможно", total, true)) passed++;
    ++total; if (run_test("10\n1 1 1 1 2 2 3 4 5 6", "большой", total)) passed++;

    cout << "\nПройдено: " << passed << " из " << total << endl;
    if (passed == total) cout << "ОТЛИЧНО! РЕШЕНИЕ ИДЕАЛЬНОЕ!" << endl;

    return 0;
}