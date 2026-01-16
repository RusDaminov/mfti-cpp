#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}
