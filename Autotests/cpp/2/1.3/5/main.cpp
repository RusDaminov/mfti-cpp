#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int num = 1;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; ++j) a[i][j] = num++;
        } else {
            for (int j = m - 1; j >= 0; --j) a[i][j] = num++;
        }
    }
    for (auto &row : a) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}
