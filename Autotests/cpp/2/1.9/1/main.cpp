#include <iostream>
using namespace std;


struct Point {
    int x, y;
};


int quadrant(const Point& p) {
    if (p.x == 0 || p.y == 0) return 0;
    if (p.x > 0 && p.y > 0) return 1;
    if (p.x < 0 && p.y > 0) return 2;
    if (p.x < 0 && p.y < 0) return 3;
    return 4;
}


int main() {
    Point p;
    cin >> p.x >> p.y;
    cout << quadrant(p) << "\n";
    return 0;
}
