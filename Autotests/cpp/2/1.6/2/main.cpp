#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    unordered_map<long long, int> seen; // число → индекс
    for (int i = 0; i < N; ++i) {
        long long complement = K - A[i];
        if (seen.count(complement)) {
            // Выводим индексы (1-based)
            cout << seen[complement] + 1 << " " << i + 1 << endl;
            return 0;
        }
        // Сохраняем текущее число с его индексом
        seen[A[i]] = i;
    }

    // Если пары не найдено
    cout << -1 << endl;
    return 0;
}
