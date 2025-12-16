#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "PUSH") {
            int x; cin >> x;
            st.push(x);
        } else if (cmd == "POP") {
            if (st.empty()) cout << "EMPTY" << endl;
            else { st.pop(); }
        } else if (cmd == "TOP") {
            if (st.empty()) cout << "EMPTY" << endl;
            else cout << st.top() << endl;
        } else if (cmd == "SIZE") {
            cout << st.size() << endl;
        }
    }
    return 0;
}
