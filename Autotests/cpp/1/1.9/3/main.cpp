#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() < 2 || s2.size() < 2) {
        cout << 0 << endl;
        return 0;
    }

    unordered_set<string> pairs_s2;
    for (size_t i = 0; i + 1 < s2.size(); ++i) {
        pairs_s2.insert(s2.substr(i, 2));
    }

    int ans = 0;
    for (size_t i = 0; i + 1 < s1.size(); ++i) {
        string p = s1.substr(i, 2);
        if (pairs_s2.count(p)) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
