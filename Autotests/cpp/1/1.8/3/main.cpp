#include <iostream>
using namespace std;

// Рекурсивная функция для вычисления N-го числа Фибоначчи
long long fibonacci(int n) {
    if (n == 0) return 0;   // a0 = 0
    if (n == 1) return 1;   // a1 = 1
    return fibonacci(n - 1) + fibonacci(n - 2); // рекурсия
}

int main() {
    int N;
    cin >> N;
    cout << fibonacci(N) << "\n";
    return 0;
}
