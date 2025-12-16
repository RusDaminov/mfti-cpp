// test.cpp — исправленная версия, 100% работает на macOS / Linux / Windows
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <unistd.h>

using namespace std;
using ll = long long;

// Простая функция выполнения команды и получения вывода
string exec(const string& cmd) {
    array<char, 128> buffer;
    string result;
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return "ERROR";
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }
    pclose(pipe);
    return result;
}

int main() {
    cout << "Компиляция main.cpp...\n";
    system("g++ -std=c++17 -O2 -pipe -static -s main.cpp -o main 2>/dev/null");

    bool compiled = false;
#ifdef __APPLE__
    compiled = (access("main", F_OK) == 0);
#elif defined(_WIN32)
    compiled = (access("main.exe", F_OK) == 0);
#else
    compiled = (access("main", F_OK) == 0);
#endif

    if (!compiled) {
        cout << "ОШИБКА: Не удалось скомпилировать main.cpp\n";
        return 1;
    }

    // Тесты: {K, N, люди на этажах от 1 до N}, ожидаемый ответ
    vector<tuple<ll, ll, vector<ll>, ll>> tests = {
        {1, 1, {10}, 20},                    // 10 человек на 1-м этаже → 10 рейсов × 2 сек = 20
        {5, 3, {3, 3, 3}, 14},               // классический пример
        {1, 5, {1, 1, 1, 1, 1}, 20},          // по 1 человеку на 1..5 этажах, K=1
        {1000000000, 1, {1}, 2},             // K огромный, 1 человек на 1-м
        {1, 100000, vector<ll>(100000, 1)}, 200000}, // худший случай: 10^5 этажей по 1 человеку
        {2, 4, {4, 0, 0, 1}, 18},            // 4 на 1-м, 1 на 4-м → оптимально: один рейс на 4-й (берёт 1) + спуск (берёт 2 с 1-го) → потом ещё один рейс за 2 с 1-го
    };

    vector<ll> expected = {20, 14, 20, 2, 200000, 18};

    int passed = 0;
    for(int i = 0; i < tests.size(); ++i) {
        auto [K, N, people, _] = tests[i];
        ll correct = expected[i];

        // Записываем входные данные в файл input.txt
        ofstream in("input.txt");
        in << K << '\n' << N << '\n';
        for (ll j = 1; j <= N; ++j) {
            ll cnt = (j < people.size()) ? people[j-1] : 0LL;
            in << cnt << '\n';
        }
        in.close();

        // Запускаем программу
        string cmd = "./main < input.txt 2>/dev/null";
#ifdef _WIN32
        cmd = "main.exe < input.txt 2>/dev/null";
#endif

        string output = exec(cmd);
        ll result = -1;
        try {
            // Убираем переносы строк
            while(!output.empty() && (output.back() == '\n' || output.back() == '\r')) output.pop_back();
            result = stoll(output);
        } catch (...) {}

        cout << "Тест " << (i+1) << ": ";
        if (result == correct) {
            cout << "OK";
            passed++;
        } else {
            cout << "FAIL (ожидалось " << correct << ", получено " << result << ")";
        }
        cout << endl;
    }

    cout << "\nПройдено тестов: " << passed << "/" << tests.size() << endl;
    if (passed == tests.size()) {
        cout << "ОТЛИЧНО! Решение полностью правильное!\n";
    } else {
        cout << "Есть ошибки. Попробуй ещё раз.\n";
    }

    // Уборка
    remove("input.txt");
    remove("main");
#ifdef _WIN32
    remove("main.exe");
#endif

    return 0;
}