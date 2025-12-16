#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string toPrefix(const string& infix) {
    stack<char> ops;
    string res;
    for (int i = infix.size() - 1; i >= 0; --i) {
        char c = infix[i];
        if (isdigit(c)) {
            res += c;
        } else if (c == ')') {
            ops.push(c);
        } else if (c == '(') {
            while (!ops.empty() && ops.top() != ')') {
                res += ops.top(); ops.pop();
            }
            ops.pop();
        } else {
            while (!ops.empty() && priority(ops.top()) > priority(c)) {
                res += ops.top(); ops.pop();
            }
            ops.push(c);
        }
    }
    while (!ops.empty()) { res += ops.top(); ops.pop(); }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << toPrefix(s) << endl;
    return 0;
}
