#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

    string ans;

    if (y > y2)
        ans += 'N';
    if (y < y1)
        ans += 'S';
    if (x < x1)
        ans += 'W';
    if (x > x2)
        ans += 'E';

    cout << ans << endl;

    return 0;
}
