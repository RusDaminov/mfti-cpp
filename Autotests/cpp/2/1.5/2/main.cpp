#include <iostream>
#include <queue>
#include <string>
using namespace std;


int main() {
    int n;
    cin >> n;
    queue<string> q;
    for (int i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            string name; cin >> name;
            q.push(name);
        } else if (cmd == "RUN") {
            if (q.empty()) cout << "IDLE" << endl;
            else { cout << q.front() << endl; q.pop(); }
        } else if (cmd == "SIZE") {
            cout << q.size() << endl;
        }
    }
    return 0;
}
