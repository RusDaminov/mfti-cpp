#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 K, N;
    cin >> K >> N;

    vector<int64> people(N + 1);
    int64 max_floor = 0;
    for (int64 i = 1; i <= N; ++i) {
        cin >> people[i];
        if (people[i] > 0) max_floor = i;  // самый высокий этаж с людьми
    }

    int64 total_time = 0;

    // Проходим этажи сверху вниз только до max_floor
    for (int64 floor = max_floor; floor >= 1; --floor) {
        if (people[floor] == 0) continue;
        int64 trips = (people[floor] + K - 1) / K;
        total_time += trips * floor * 2;
    }

    cout << total_time << "\n";
    return 0;
}
