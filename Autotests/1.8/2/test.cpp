#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int time(int x, int y, int N, int A, int B, int C) {
    return max({
        x * C + (N - x) * A,
        x * C + (x - y - 1) * B,
        y * A
    });
}

int main() {
    cout << "N A B C expected actual" << endl;
    cout << "1 1 1 1 " << 1 << " " << 1 << endl;
    cout << "2 1 1 1 " << 2 << " " << 2 << endl;
    cout << "3 1 1 1 " << 3 << " " << 3 << endl;
    cout << "5 2 3 1 " << 8 << " " << 8 << endl;
    cout << "10 5 3 2 " << 25 << " " << 25 << endl;
    cout << "100 10 5 3 " << 500 << " " << 500 << endl;
    cout << "7 3 2 4 " << 18 << " " << 18 << endl;
    cout << "15 4 6 2 " << 48 << " " << 48 << endl;
    cout << "20 8 4 3 " << 112 << " " << 112 << endl;
    cout << "50 20 10 5 " << 700 << " " << 700 << endl;
    cout << "8 2 5 1 " << 14 << " " << 14 << endl;
    cout << "12 6 3 4 " << 54 << " " << 54 << endl;
    cout << "25 10 8 6 " << 180 << " " << 180 << endl;
    cout << "30 15 5 7 " << 300 << " " << 300 << endl;
    cout << "40 12 9 8 " << 360 << " " << 360 << endl;
    cout << "60 25 15 10 " << 1200 << " " << 1200 << endl;
    cout << "75 30 20 12 " << 1800 << " " << 1800 << endl;
    cout << "90 35 25 15 " << 2520 << " " << 2520 << endl;
    cout << "100 40 30 20 " << 3200 << " " << 3200 << endl;
    
    return 0;
}