#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree {
    int n;
    vector<long long> t;

    SegmentTree(int size) {
        n = size;
        t.assign(4 * n, 0);
    }

    void build(const vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    long long sum(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return t[v];
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) t[v] = val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(v*2, tl, tm, pos, val);
            else update(v*2+1, tm+1, tr, pos, val);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    SegmentTree st(n);
    st.build(a, 1, 0, n-1);

    for (int i = 0; i < m; ++i) {
        string cmd; cin >> cmd;
        if (cmd == "sum") {
            int l, r; cin >> l >> r;
            --l; --r;
            cout << st.sum(1, 0, n-1, l, r) << "\n";
        } else if (cmd == "update") {
            int pos, val; cin >> pos >> val;
            --pos;
            st.update(1, 0, n-1, pos, val);
        }
    }
    return 0;
}
