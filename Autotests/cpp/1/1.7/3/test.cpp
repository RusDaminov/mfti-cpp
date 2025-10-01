#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int section(int k) {
    if (k <= 36)
        return (k - 1) / 4;
    else
        return 8 - (k - 37) / 2;
}

int main() {
    int n;
    cin >> n;

    int count[9] = {0};

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        count[section(k)] += 1;
    }

    int ans = 0;
    int curr = 0;

    for (int i = 0; i < 9; ++i) {
        if (count[i] == 6) {
            curr += 1;
            ans = max(ans, curr);
        } else {
            curr = 0;
        }
    }

    cout << ans << endl;

    return 0;
}