// test.cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, m, k, c;
    cin >> n >> m >> k >> c;
    c--; // Переводим в 0-based индексацию

    long long ans = 0;

    // Оптимальное решение: для каждого остатка r от 0 до k-1
    // считаем количество строк с i ≡ r (mod k) и столбцов с j ≡ (c-r) (mod k)
    for (long long r = 0; r < k; r++) {
        // Количество строк с остатком r
        long long rows_count = (n - r + k - 1) / k;
        if (r >= n) rows_count = 0;
        
        // Для строк с остатком r нужны столбцы с остатком (c - r) mod k
        long long col_rem = (c - r + k) % k;
        
        // Количество столбцов с нужным остатком
        long long cols_count = (m - col_rem + k - 1) / k;
        if (col_rem >= m) cols_count = 0;
        
        ans += rows_count * cols_count;
    }

    cout << ans << endl;

    return 0;
}