#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k, n;
    cin >> k >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    ll cur = 0;                    // сколько человек уже "собрано" сверху
    for (int i = n; i >= 1; --i) {
        cur += a[i];
        if (cur > 0) {
            ll trips = (cur + k - 1) / k;  // сколько рейсов нужно для cur человек
            ans += trips * 2 * i;          // каждый рейс: подъём до i-го и спуск
            cur = 0;                       // все уехали
        }
    }
    cout << ans << '\n';
    return 0;
}