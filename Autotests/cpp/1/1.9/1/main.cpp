#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        freq[A[i]]++;
    }

    // Находим школу с максимальным числом участников
    int maxcount = 0, maxval = 0;
    for (auto &p : freq) {
        if (p.second > maxcount) {
            maxcount = p.second;
            maxval = p.first;
        }
    }

    // Формируем массив A: сначала все из самой многочисленной школы, затем остальные по возрастанию
    vector<int> sortedA;
    for (int i = 0; i < maxcount; ++i) sortedA.push_back(maxval);
    for (auto &p : freq) {
        if (p.first == maxval) continue;
        for (int i = 0; i < p.second; ++i) sortedA.push_back(p.first);
    }
    sort(sortedA.begin() + maxcount, sortedA.end());

    vector<int> B(n);
    int j = 0;
    // Заполняем с шагом 2
    for (int i = 0; i < n; i += 2) {
        B[i] = sortedA[j++];
    }
    for (int i = 1; i < n; i += 2) {
        B[i] = sortedA[j++];
    }

    // Проверяем условие задачи
    bool ok = true;
    for (int i = 1; i < n; ++i) {
        if (B[i] == B[i - 1]) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << 0 << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << B[i];
            if (i != n - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
