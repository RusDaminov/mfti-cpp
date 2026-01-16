#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int sum_pos = 0;
    for (int x : a) if (x > 0) sum_pos += x;


    int min_idx = min_element(a.begin(), a.end()) - a.begin();
    int max_idx = max_element(a.begin(), a.end()) - a.begin();


    int l = min(min_idx, max_idx), r = max(min_idx, max_idx);
    int prod = 1;
    if (r - l > 1) {
        for (int i = l + 1; i < r; ++i) prod *= a[i];
    } else {
        prod = 0;
    }
    cout << sum_pos << " " << prod << endl;
    return 0;
}
