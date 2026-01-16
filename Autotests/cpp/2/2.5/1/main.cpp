#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "PUSH") {
            int x; cin >> x;
            q.push(x);
        } else if (cmd == "POP") {
            if (q.empty()) cout << "EMPTY" << endl;
            else q.pop();
        } else if (cmd == "FRONT") {
            if (q.empty()) cout << "EMPTY" << endl;
            else cout << q.front() << endl;
        } else if (cmd == "SIZE") {
            cout << q.size() << endl;
        }
    }
    return 0;
}
