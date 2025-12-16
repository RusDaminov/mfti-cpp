#include <iostream>
#include <string>
using namespace std;

string python_slice(const string& s, int start, int end, int step) {
    int n = s.size();
    // Обработка отрицательных индексов
    if (start < 0) start += n;
    if (end < 0) end += n;
    // Ограничения по границам
    if (step > 0) {
        if (start < 0) start = 0;
        if (end > n) end = n;
    } else {
        if (start >= n) start = n - 1;
        if (end < -1) end = -1;
    }
    string res;
    if (step > 0) {
        for (int i = start; i < end; i += step)
            if (i >= 0 && i < n) res += s[i];
    } else if (step < 0) {
        for (int i = start; i > end; i += step)
            if (i >= 0 && i < n) res += s[i];
    }
    return res;
}

int main() {
    string s;
    int start, end, step;
    cin >> s >> start >> end >> step;
    cout << python_slice(s, start, end, step) << endl;
    return 0;
}
