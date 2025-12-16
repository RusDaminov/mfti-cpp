#include <iostream>
#include <vector>
using namespace std;

int binary_search_first(const vector<int>& a, int x) {
    int left = 0, right = (int)a.size() - 1;
    int ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x) {
            ans = mid;
            right = mid - 1;
        } else if (a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int x; cin >> x;
    cout << binary_search_first(a, x) << "\n";
    return 0;
}
