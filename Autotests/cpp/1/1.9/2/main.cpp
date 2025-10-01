#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int ans1 = 0;
    int ans2 = -1;

    // Перебираем все возможные подмассивы
    for (int i = 0; i < n; ++i) {
        int max_val = a[i];
        for (int j = i + 2; j < n; ++j) {
            max_val = max(max_val, a[j]);
            if (a[i] < max_val && a[j] < max_val) {
                // Проверяем, является ли текущий подмассив лучшим (короче)
                if (j - i < ans2 - ans1 || ans2 == -1) {
                    ans1 = i;
                    ans2 = j;
                }
            }
        }
    }

    if (ans2 != -1)
        cout << ans1 + 1 << " " << ans2 + 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
