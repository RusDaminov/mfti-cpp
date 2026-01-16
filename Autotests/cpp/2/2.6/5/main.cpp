#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x, m;
    cin >> n >> x >> m;

    unordered_map<long long, long long> freq;
    long long result = 0;

    for (int _ = 0; _ < n; ++_) {
        string s;
        cin >> s;
        long long hash = 0;

        // ✅ Вычисляем справа налево
        for (int i = s.size() - 1; i >= 0; --i) {
            int digit = s[i] - '0';
            hash = (hash * x + digit) % m;
        }

        result += freq[hash];
        freq[hash]++;
    }

    cout << result << "\n";
    return 0;
}
