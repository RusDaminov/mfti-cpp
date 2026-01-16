#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<long long>> dp(K + 1, vector<long long>(N + 1, 0));
    
    // dp[i][j] - количество разбиений j на i слагаемых
    dp[0][0] = 1;
    
    for (int i = 1; i <= K; ++i) {
        for (int j = i; j <= N; ++j) {
            // Формула для разбиений на неупорядоченные слагаемые
            dp[i][j] = dp[i-1][j-1] + dp[i][j-i];
        }
    }
    
    cout << dp[K][N] << "\n";
    return 0;
}