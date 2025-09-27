#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int ans = 0;

    for (size_t i = 0; i + 1 < s1.length(); ++i) {
        string substr = s1.substr(i, 2);
        if (s2.find(substr) != string::npos)
            ans++;
    }

    cout << ans << endl;

    return 0;
}
