#include <iostream>
#include <queue>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        q.push(x);
    }
    k = k % n;
    for (int i = 0; i < k; ++i) {
        int t = q.front(); q.pop(); q.push(t);
    }
    for (int i = 0; i < n; ++i) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
