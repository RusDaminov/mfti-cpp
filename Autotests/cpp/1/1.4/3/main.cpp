#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Движение по оси X
    if (x2 > x1) {
        for (int i = 0; i < x2 - x1; ++i)
            cout << "E\n";
    } else {
        for (int i = 0; i < x1 - x2; ++i)
            cout << "W\n";
    }

    // Движение по оси Y
    if (y2 > y1) {
        for (int i = 0; i < y2 - y1; ++i)
            cout << "N\n";
    } else {
        for (int i = 0; i < y1 - y2; ++i)
            cout << "S\n";
    }

    return 0;
}
