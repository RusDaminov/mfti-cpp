#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int num = 1;
    int top = 0, left = 0, bottom = n - 1, right = m - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; ++j) a[top][j] = num++;
        ++top;
        for (int i = top; i <= bottom; ++i) a[i][right] = num++;
        --right;
        if (top <= bottom) {
            for (int j = right; j >= left; --j) a[bottom][j] = num++;
            --bottom;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) a[i][left] = num++;
            ++left;
        }
    }
    for (auto &row : a) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}
