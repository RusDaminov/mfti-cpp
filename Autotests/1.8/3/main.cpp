#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Функция, вычисляющая время по заданным x и y
int time(int x, int y, int A, int B, int C) {
    return max({
        x * C + (N - x) * A,
        x * C + (x - y - 1) * B,
        y * A
    });
}

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    int ans = N * A;

    // Вычисляем X по приближенной формуле
    long long numerator = 1LL * N * A * A + 1LL * N * A * B;
    long long denominator = 2LL * A * B + 1LL * A * A - 1LL * C * B;
    int X = (denominator != 0) ? static_cast<int>(numerator / denominator) : 0;

    // Перебираем X и X+1
    for (int x : {X, X + 1}) {
        if (x >= 0 && x <= N) {
            int y = (C + B) * x / (A + B);
            ans = min(ans, time(x, y, A, B, C));
        }
    }

    cout << ans << endl;

    return 0;
}
