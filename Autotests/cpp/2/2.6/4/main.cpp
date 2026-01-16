#include <iostream>
#include <unordered_map>
using namespace std;


unordered_map<int, long long> cache;


long long fact(int n) {
    if (n == 0 || n == 1) return 1;
    if (cache.count(n)) return cache[n];
    return cache[n] = n * fact(n - 1);
}


int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << fact(n) << endl;
    }
    return 0;
}
