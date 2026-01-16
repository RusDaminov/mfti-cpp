#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

// --- Graph Implementation ---
struct Node {
    int vertex;
    Node* next;
    Node(int v) : vertex(v), next(nullptr) {}
};

struct Graph {
    int n;
    vector<Node*> adj;
    Graph(int size) : n(size), adj(size, nullptr) {}

    void addEdge(int u, int v) {
        Node* node = new Node(v); // keep 1-based
        node->next = adj[u];
        adj[u] = node;
    }

    vector<int> getNeighbors(int u) {
        vector<int> neighbors;
        Node* cur = adj[u];
        while (cur) {
            neighbors.push_back(cur->vertex);
            cur = cur->next;
        }
        sort(neighbors.begin(), neighbors.end());
        return neighbors;
    }
};

bool runTest(const string& input, const vector<vector<int>>& expected) {
    istringstream in(input);
    int n, m;
    in >> n >> m;

    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        in >> u >> v;
        g.addEdge(u-1, v);
        g.addEdge(v-1, u);
    }

    int q;
    in >> q;
    bool ok = true;

    for (int i = 0; i < q; ++i) {
        int u;
        in >> u;
        vector<int> out = g.getNeighbors(u-1);
        if (out != expected[i]) {
            ok = false;
            cout << "Test failed for query " << i+1 << " (vertex " << u << ")\n";
            cout << "Expected: ";
            for (int x : expected[i]) cout << x << " ";
            cout << "\nGot: ";
            for (int x : out) cout << x << " ";
            cout << "\n";
        }
    }
    return ok;
}

int main() {
    struct Test {
        string input;
        vector<vector<int>> expected;
    };

    vector<Test> tests = {
        {
            "4 3\n1 2\n2 3\n3 4\n2\n1\n3\n",
            {{2},{2,4}}
        },
        {
            "5 4\n1 2\n2 3\n3 4\n4 5\n1\n3\n",
            {{2,4}}
        },
        {
            "2 1\n1 2\n2\n1\n2\n",
            {{2},{1}}
        },
        {
            "3 2\n1 2\n2 3\n3\n1\n2\n3\n",
            {{2},{1,3},{2}}
        }
    };

    int passed = 0;
    for (int i = 0; i < tests.size(); ++i) {
        if (runTest(tests[i].input, tests[i].expected)) {
            passed++;
        }
    }

    cout << "Passed " << passed << "/" << tests.size() << " tests.\n";
    return 0;
}
