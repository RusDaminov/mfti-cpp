#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> res(n + 1);
    for (int i = 1; i <= n; ++i) {
        int j;
        cin >> j;
        res[j] = n + 1 - i;
    }
    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << " ";
        cout << res[i];
    }
    cout << "\n";
}