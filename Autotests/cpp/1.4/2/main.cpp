
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long total = (long long)n * m; // чтобы избежать переполнения при больших числах
    cout << (total + 1) / 2 << endl;

    return 0;
}
