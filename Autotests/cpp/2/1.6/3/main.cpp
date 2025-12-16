#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (auto &w : words) cin >> w;
    unordered_map<string, vector<string>> groups;
    for (const string &w : words) {
        string key = w;
        sort(key.begin(), key.end());
        groups[key].push_back(w);
    }
    for (auto &p : groups) {
        for (const string &w : p.second)
            cout << w << " ";
        cout << endl;
    }
    return 0;
}
