#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    
    for (auto &row : a)
        for (int &x : row)
            cin >> x;

    for (int i = 0; i < n; ++i) {
        a[i][i] = 0;
        a[i][n - 1 - i] = 0;
    }

    for (auto &row : a) {
        for (int j = 0; j < n; ++j) {
            cout << row[j];
            if (j < n - 1) cout << " "; // пробел только между элементами
        }
        cout << endl;
    }
    return 0;
}
