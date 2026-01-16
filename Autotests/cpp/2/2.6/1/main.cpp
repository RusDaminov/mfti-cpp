#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;


int main() {
    string s;
    cin >> s;
    unordered_set<string> substrings;
    int n = s.size();
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            substrings.insert(s.substr(i, len));
        }
    }
    cout << substrings.size() << endl;
    return 0;
}
