#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // -----------------------------
    // Способ 1: классический вложенный цикл
    // -----------------------------
    cout << "Method 1: Nested loops\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << i * j << "\t";
        }
        cout << "\n";
    }

    cout << "\n";

    // -----------------------------
    // Способ 2: одномерный массив
    // -----------------------------
    cout << "Method 2: One-dimensional array\n";
    vector<int> row(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            row[j] = i * (j + 1);  // формула умножения
        }
        for (int val : row) cout << val << "\t";
        cout << "\n";
    }

    return 0;
}
