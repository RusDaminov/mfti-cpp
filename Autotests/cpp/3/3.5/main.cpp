#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    dp[0][0] = 1;
    for (int n = 1; n <= N; ++n) {
        for (int k = 0; k <= K; ++k) {
            for (int i = 0; i <= min(k, n - 1); ++i) {
                dp[n][k] = (dp[n][k] + dp[n - 1][k - i]) % MOD;
            }
        }
    }
    cout << dp[N][K] << "\n";
    return 0;
}
