#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b, l, r, eps;
    cin >> a >> b >> l >> r >> eps;
    double x = -b / a;
    if (x + eps >= l && x - eps <= r) {
        cout << fixed << setprecision(4) << x << endl;
    } else {
        cout << "No root on segment" << endl;
    }
    return 0;
}
