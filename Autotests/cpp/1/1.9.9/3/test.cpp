// test.cpp — окончательная версия с правильными ответами
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <fstream>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
using namespace std;
using ll = long long;

string exec(const string& cmd) {
    array<char, 128> buffer{};
    string result;
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return "ERR";
    while (fgets(buffer.data(), buffer.size(), pipe)) {
        result += buffer.data();
    }
    pclose(pipe);
    return result;
}

int main() {
    cout << "Компиляция main.cpp...\n";
    system("g++ -std=c++17 -O2 -pipe -s main.cpp -o main 2>/dev/null || clang++ -std=c++17 main.cpp -o main 2>/dev/null");

    bool ok = (access("main", F_OK) == 0);
#ifdef _WIN32
    ok = ok || (access("main.exe", F_OK) == 0);
#endif
    if (!ok) {
        cout << "ОШИБКА: не удалось скомпилировать main.cpp\n";
        return 1;
    }

    // K, N, люди на этажах 1..N, правильный ответ
    vector<tuple<ll, ll, vector<ll>, ll>> tests = {
        {1, 1, {10}, 20},           // 10 человек на 1-м → 10 рейсов × 2 сек = 20
        {5, 3, {3, 3, 3}, 12},      // оптимально: 2 рейса до 3-го этажа → 2×(3×2) = 12
        {1, 5, {1,1,1,1,1}, 30},     // по 1 человеку, K=1 → 2+4+6+8+10 = 30
        {1000000000, 1, {1}, 2},    // 1 человек на 1-м → 1 рейс × 2 = 2
        {2, 4, {4,0,0,1}, 12},      // 1 на 4-м, 4 на 1-м → 2 рейса до 4-го = 16? Нет!
                                    // Правильно: 1 рейс: берёт 1 с 4-го + 1 с 1-го → ост 3 на 1-м
                                    // 2 рейс: берёт 2 с 1-го → всего 2 рейса до 4-го → 2×8 = 16? Нет!
                                    // Подожди, давай по-честному:
                                    // Лучше: 1 рейс до 4 → берёт 1 с 4 + 1 с 1 → спуск
                                    // 2 рейс до 1 → берёт 2 с 1 → спуск → 8 + 2 = 10? Нет!
                                    // А на самом деле: можно 1 рейс до 4 → берёт 1+1 → ост 3
                                    // Потом рейс до 1 → берёт 2 → ост 1 → ещё рейс до 1 → берёт 1
                                    // → 8 + 2 + 2 = 12 — да, 12!
        {1, 6, {1,1,1,1,1,1}, 42}   // 2+4+6+8+10+12 = 42
    };

    // Правильные ответы:
    vector<ll> correct = {20, 12, 30, 2, 12, 42};

    int passed = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        auto [K, N, people, _] = tests[i];
        ll expected = correct[i];

        ofstream f("input.txt");
        f << K << '\n' << N << '\n';
        for (ll p : people) f << p << '\n';
        for (ll j = people.size(); j < (size_t)N; ++j) f << 0 << '\n';
        f.close();

        string cmd = "./main < input.txt 2>/dev/null";
#ifdef _WIN32
        cmd = "main.exe < input.txt 2>/dev/null";
#endif
        string out = exec(cmd);
        while (!out.empty() && (out.back() == '\n' || out.back() == '\r')) out.pop_back();
        ll res = -1;
        try { res = stoll(out); } catch(...) {}

        cout << "Тест " << (i+1) << ": ";
        if (res == expected) {
            cout << "OK\n";
            passed++;
        } else {
            cout << "FAIL (ожидалось " << expected << ", получил " << res << ")\n";
        }
    }

    cout << "\nПройдено: " << passed << "/6\n";
    if (passed == 6) cout << "ОТЛИЧНО! Решение правильное!\n";

    remove("input.txt");
    remove("main");
#ifdef _WIN32
    remove("main.exe");
#endif
    return 0;
}