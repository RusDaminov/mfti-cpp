#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    istringstream iss(s);
    stack<int> st;
    string token;
    while (iss >> token) {
        if (isdigit(token[0])) st.push(stoi(token));
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b);
        }
    }
    cout << st.top() << endl;
    return 0;
}
