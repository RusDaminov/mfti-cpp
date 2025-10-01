#include <iostream>
#include <string>
using namespace std;

int find_substring(const string& text, const string& pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();
    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        for (; j < m; ++j) {
            if (text[i + j] != pattern[j]) break;
        }
        if (j == m) return i; // найдено вхождение
    }
    return -1; // не найдено
}

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    int pos = find_substring(text, pattern);
    cout << pos << "\n";
    return 0;
}
