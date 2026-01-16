#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


int main() {
    string s;
    cin >> s;
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    int max_cnt = 0;
    char ans = s[0];
    for (char c : s) {
        if (freq[c] > max_cnt) {
            max_cnt = freq[c];
            ans = c;
        }
    }
    cout << ans << endl;
    return 0;
}
