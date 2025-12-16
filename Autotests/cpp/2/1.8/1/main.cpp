#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, const vector<vector<int>>& g, vector<bool>& visited) {
    visited[v] = true;
    for (int to : g[v]) {
        if (!visited[to]) dfs(to, g, visited);
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> visited(n, false);
    dfs(0, g, visited);
    bool connected = true;
    for (bool v : visited) {
        if (!v) connected = false;
    }
    cout << (connected ? "YES" : "NO") << "\n";
    return 0;
}
