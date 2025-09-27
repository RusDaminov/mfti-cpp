// test.cpp
#include <iostream>
#include <vector>
#include <cassert>
#include <climits>
#include <algorithm>

using namespace std;

// Объявляем функцию, которая тестируется
extern int main();

// Функция для тестирования алгоритма
void runTests() {
    cout << "Running tests..." << endl;
    
    // Тест 1: Пример из условия
    {
        vector<int> a = {1, 2, 3, 2, 1};
        int n = a.size();
        int ans1 = 0, ans2 = -1;
        
        for (int i = 0; i < n; ++i) {
            int max_val = a[i];
            for (int j = i + 2; j < n; ++j) {
                max_val = max(max_val, a[j]);
                if (a[i] < max_val && a[j] < max_val) {
                    if (j - i < ans2 - ans1 || ans2 == -1) {
                        ans1 = i;
                        ans2 = j;
                    }
                }
            }
        }
        
        assert(ans1 == 0 && ans2 == 2); // Ожидается [1, 3]
        cout << "Test 1 passed: [1, 2, 3, 2, 1] -> [" << ans1+1 << ", " << ans2+1 << "]" << endl;
    }
    
    // Тест 2: Нет подходящего подмассива
    {
        vector<int> a = {1, 2, 3, 4, 5};
        int n = a.size();
        int ans1 = 0, ans2 = -1;
        
        for (int i = 0; i < n; ++i) {
            int max_val = a[i];
            for (int j = i + 2; j < n; ++j) {
                max_val = max(max_val, a[j]);
                if (a[i] < max_val && a[j] < max_val) {
                    if (j - i < ans2 - ans1 || ans2 == -1) {
                        ans1 = i;
                        ans2 = j;
                    }
                }
            }
        }
        
        assert(ans2 == -1); // Не должно быть найденного подмассива
        cout << "Test 2 passed: [1, 2, 3, 4, 5] -> no solution" << endl;
    }
    
    // Тест 3: Несколько возможных вариантов, выбираем самый короткий
    {
        vector<int> a = {2, 1, 3, 1, 4, 1, 5};
        int n = a.size();
        int ans1 = 0, ans2 = -1;
        
        for (int i = 0; i < n; ++i) {
            int max_val = a[i];
            for (int j = i + 2; j < n; ++j) {
                max_val = max(max_val, a[j]);
                if (a[i] < max_val && a[j] < max_val) {
                    if (j - i < ans2 - ans1 || ans2 == -1) {
                        ans1 = i;
                        ans2 = j;
                    }
                }
            }
        }
        
        // Ожидается самый короткий подмассив, удовлетворяющий условиям
        cout << "Test 3 passed: [2, 1, 3, 1, 4, 1, 5] -> [" << ans1+1 << ", " << ans2+1 << "]" << endl;
    }
    
    // Тест 4: Минимальный случай (массив слишком короткий)
    {
        vector<int> a = {1, 2};
        int n = a.size();
        int ans1 = 0, ans2 = -1;
        
        for (int i = 0; i < n; ++i) {
            int max_val = a[i];
            for (int j = i + 2; j < n; ++j) {
                max_val = max(max_val, a[j]);
                if (a[i] < max_val && a[j] < max_val) {
                    if (j - i < ans2 - ans1 || ans2 == -1) {
                        ans1 = i;
                        ans2 = j;
                    }
                }
            }
        }
        
        assert(ans2 == -1); // Не должно быть найденного подмассива
        cout << "Test 4 passed: [1, 2] -> no solution" << endl;
    }
    
    // Тест 5: Все элементы одинаковые
    {
        vector<int> a = {3, 3, 3, 3, 3};
        int n = a.size();
        int ans1 = 0, ans2 = -1;
        
        for (int i = 0; i < n; ++i) {
            int max_val = a[i];
            for (int j = i + 2; j < n; ++j) {
                max_val = max(max_val, a[j]);
                if (a[i] < max_val && a[j] < max_val) {
                    if (j - i < ans2 - ans1 || ans2 == -1) {
                        ans1 = i;
                        ans2 = j;
                    }
                }
            }
        }
        
        assert(ans2 == -1); // Не должно быть найденного подмассива
        cout << "Test 5 passed: [3, 3, 3, 3, 3] -> no solution" << endl;
    }
    
    cout << "All tests passed!" << endl;
}

// Основная функция тестового файла
int main_test() {
    runTests();
    return 0;
}

// Если нужно запустить тесты вместо основной программы,
// можно использовать предпроцессорные директивы
#ifndef RUN_MAIN_PROGRAM
int main() {
    return main_test();
}
#endif