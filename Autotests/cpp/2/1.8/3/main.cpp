#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int q; cin >> q;
    priority_queue<int> pq;
    for (int i = 0; i < q; ++i) {
        string cmd; cin >> cmd;
        if (cmd == "insert") {
            int x; cin >> x;
            pq.push(x);
        } else if (cmd == "extract") {
            if (pq.empty()) cout << "EMPTY\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
    return 0;
}
