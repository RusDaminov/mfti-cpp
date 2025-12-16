#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n, x;
    cin >> n;
    vector<int> a(n);
    for (int &y : a) cin >> y;
    cin >> x;
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
