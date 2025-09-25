#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;

    int n4 = m % 3;
    int n3 = (m - 4 * n4) / 3;

    if (n3 >= 0)
        cout << n3 << endl << n4 << endl;
    else
        cout << "0\n0\n";

    return 0;
}