#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int count_ways(const vector<int>& coins, int S) {
    vector<int> dp(S + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int sum = coin; sum <= S; ++sum) {
            dp[sum] += dp[sum - coin];
        }
    }
    return dp[S];
}

void test() {
    struct TestCase {
        int n;
        int S;
        vector<int> coins;
        int expected;
    };
    
    vector<TestCase> testCases = {
        {3, 5, {1, 2, 5}, 4},
        {2, 3, {2, 3}, 0},
        {4, 10, {2, 3, 5, 6}, 5},
        {1, 7, {1}, 1},
        {3, 0, {1, 2, 3}, 1}
    };
    
    for (size_t i = 0; i < testCases.size(); ++i) {
        int result = count_ways(testCases[i].coins, testCases[i].S);
        assert(result == testCases[i].expected);
        cout << "Test " << i + 1 << " passed" << endl;
    }
    
    cout << "All tests passed!" << endl;
}

int main() {
    test();
    return 0;
}