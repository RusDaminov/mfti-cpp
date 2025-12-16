#include <iostream>
#include <string>
using namespace std;


int main() {
    string s, t;
    cin >> s >> t;
    int pos = s.find(t);
    cout << pos << endl;
    return 0;
}