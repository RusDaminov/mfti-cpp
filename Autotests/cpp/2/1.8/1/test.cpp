#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
using namespace std;

void task1_solution(istream& cin, ostream& cout) {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> visited(n, false);
    function<void(int)> dfs = [&](int v) {
        visited[v] = true;
        for (int to : g[v]) if (!visited[to]) dfs(to);
    };
    dfs(0);
    bool connected = true;
    for (bool v : visited) if (!v) connected = false;
    cout << (connected ? "YES" : "NO") << "\n";
}

int main() {
    struct Test { string input; string expected; };
    vector<Test> tests = {
        {"4 3\n1 2\n2 3\n3 4\n", "YES"},
        {"4 2\n1 2\n3 4\n", "NO"},
        {"1 0\n", "YES"},
        {"5 4\n1 2\n2 3\n3 4\n4 5\n", "YES"},
        {"3 1\n2 3\n", "NO"}
    };
    int passed = 0;
    for (auto &t : tests) {
        istringstream in(t.input);
        ostringstream out;
        task1_solution(in, out);
        string res = out.str(); if (!res.empty() && res.back() == '\n') res.pop_back();
        if (res == t.expected) ++passed;
        else cerr << "Failed test!\nInput:\n" << t.input << "Expected: " << t.expected << " Got: " << res << "\n";
    }
    cout << "Passed " << passed << "/" << tests.size() << " tests\n";
}
