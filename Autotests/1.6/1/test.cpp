#include <iostream>
#include <cassert>
using namespace std;

int solve(long long N, long long K) {
    long long solved = 0;
    int day = 0;
    
    while (solved < N) {
        solved += K;
        K++;
        day++;
    }
    
    return day;
}

void runTests() {
    cout << "Запуск тестов..." << endl;
    
    assert(solve(10, 2) == 4);
    cout << "Тест 1 пройден" << endl;
    
    assert(solve(1, 1) == 1);
    cout << "Тест 2 пройден" << endl;
    
    assert(solve(1000000000, 1) == 44721);
    cout << "Тест 3 пройден" << endl;
    
    assert(solve(2147483647, 1) == 65536);
    cout << "Тест 4 пройден" << endl;
    
    long long N5 = 46341LL * (46341 + 1) / 2;
    assert(solve(N5, 1) == 46341);
    cout << "Тест 5 пройден" << endl;
    
    cout << "Все тесты пройдены успешно!" << endl;
}

int main() {
    runTests();
    return 0;
}