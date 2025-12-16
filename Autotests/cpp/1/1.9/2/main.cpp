#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n < 3) {
        cout << "0\n";
        return 0;
    }

    long long best_len = 4e18;
    int best_l = -1, best_r = -1;

    long long prev_h, cur_h;
    cin >> prev_h >> cur_h;  // первые два элемента
    int cur_len = 1;
    int plateau_start = 2;   // 1-based начало плато

    for (int i = 2; i < n; ++i) {
        long long next_h;
        cin >> next_h;

        if (next_h == cur_h) {
            cur_len++;  // продолжаем плато
        } else {
            if (prev_h < cur_h && next_h < cur_h) {
                long long len = cur_len + 2;  // левый и правый элементы
                if (len < best_len) {
                    best_len = len;
                    best_l = plateau_start - 1;      // левый элемент перед плато
                    best_r = plateau_start + cur_len; // правый элемент после плато
                }
            }
            // начинаем новое плато
            prev_h = cur_h;
            cur_h = next_h;
            cur_len = 1;
            plateau_start = i + 1;  // 1-based
        }
    }

    if (best_len > n + 10LL) {
        cout << "0\n";
    } else {
        cout << best_len << "\n";
        cout << best_l << " " << best_r << "\n";
    }

    return 0;
}
