#include <iostream>
#include <vector>
using namespace std;

int count_ways(const vector<int>& coins, int S) {
    vector<int> dp(S + 1, 0);
    dp[0] = 1; // 1 способ получить сумму 0 — не брать монеты

    for (int coin : coins) {
        for (int sum = coin; sum <= S; ++sum) {
            dp[sum] += dp[sum - coin];
        }
    }
    return dp[S];
}

int main() {
    int n, S;
    cin >> n >> S;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];

    cout << count_ways(coins, S) << "\n";
    return 0;
}
