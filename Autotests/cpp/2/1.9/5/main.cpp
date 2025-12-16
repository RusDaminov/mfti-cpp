#include <iostream>
#include <vector>
using namespace std;

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
        Node* node = new Node(v);
        node->next = adj[u];
        adj[u] = node;
    }

    void printNeighbors(int u) {
        Node* cur = adj[u];
        while (cur) {
            cout << cur->vertex << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

int main() {
    int n, m; cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        g.addEdge(u, v);
        g.addEdge(v, u);
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int u; cin >> u;
        --u;
        g.printNeighbors(u);
    }
    return 0;
}
