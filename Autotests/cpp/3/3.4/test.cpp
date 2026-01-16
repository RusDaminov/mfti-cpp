#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// Функция для сравнения результатов
bool runTest(int N, int K, long long expected, const string& testName) {
    // Создаем входные данные
    ofstream input("input.txt");
    if (!input) {
        cerr << "Не могу создать input.txt" << endl;
        return false;
    }
    input << N << " " << K;
    input.close();
    
    // Запускаем программу с перенаправлением ввода-вывода
    #ifdef _WIN32
        system("main.exe < input.txt > output.txt 2>nul");
    #else
        system("./main < input.txt > output.txt 2>/dev/null");
    #endif
    
    // Читаем результат
    ifstream output("output.txt");
    if (!output) {
        cerr << "Не могу прочитать output.txt" << endl;
        return false;
    }
    
    long long result;
    output >> result;
    output.close();
    
    bool passed = (result == expected);
    
    cout << testName << ": ";
    if (passed) {
        cout << "ПРОЙДЕН" << endl;
    } else {
        cout << "ПРОВАЛЕН" << endl;
        cout << "  Ожидалось: " << expected << endl;
        cout << "  Получено: " << result << endl;
    }
    
    return passed;
}

int main() {
    // Компилируем main.cpp
    cout << "Компиляция main.cpp..." << endl;
    
    #ifdef _WIN32
        int compileResult = system("g++ -std=c++11 -o main.exe main.cpp");
    #else
        int compileResult = system("g++ -std=c++11 -o main main.cpp");
    #endif
    
    if (compileResult != 0) {
        cerr << "Ошибка компиляции!" << endl;
        return 1;
    }
    
    cout << "Компиляция успешна!" << endl;
    cout << "\nЗапуск тестов..." << endl;
    cout << "=================" << endl;
    
    vector<pair<pair<int, int>, long long>> tests = {
        {{5, 2}, 2},      // 5 = 1+4, 2+3
        {{6, 3}, 3},      // 6 = 1+1+4, 1+2+3, 2+2+2
        {{7, 2}, 3},      // 7 = 1+6, 2+5, 3+4
        {{8, 4}, 5},      // 8 = 1+1+1+5, 1+1+2+4, 1+1+3+3, 1+2+2+3, 2+2+2+2
        {{10, 3}, 8},     // 10 с 3 слагаемыми
        {{1, 1}, 1},      // 1 = 1
        {{1, 2}, 0},      // Невозможно представить 1 как сумму 2 положительных чисел
        {{4, 2}, 2},      // 4 = 1+3, 2+2
        {{10, 1}, 1},     // 10 = 10
        {{10, 10}, 1},    // 10 = 1+1+1+1+1+1+1+1+1+1
        {{0, 0}, 1},      // Пустое разбиение
        {{20, 5}, 84},    // 20 на 5 слагаемых
    };
    
    int passedCount = 0;
    int totalTests = tests.size();
    
    for (size_t i = 0; i < tests.size(); ++i) {
        int N = tests[i].first.first;
        int K = tests[i].first.second;
        long long expected = tests[i].second;
        
        string testName = "Тест " + to_string(i+1) + " (N=" + to_string(N) + 
                         ", K=" + to_string(K) + ")";
        
        if (runTest(N, K, expected, testName)) {
            passedCount++;
        }
    }
    
    cout << "\n=================" << endl;
    cout << "Итого: " << passedCount << "/" << totalTests << " тестов пройдено" << endl;
    
    // Удаляем временные файлы
    remove("input.txt");
    remove("output.txt");
    #ifdef _WIN32
        remove("main.exe");
    #else
        remove("main");
    #endif
    
    if (passedCount == totalTests) {
        cout << "\nВСЕ ТЕСТЫ ПРОЙДЕНЫ УСПЕШНО!" << endl;
        return 0;
    } else {
        cout << "\nТЕСТЫ ПРОВАЛЕНЫ!" << endl;
        return 1;
    }
}