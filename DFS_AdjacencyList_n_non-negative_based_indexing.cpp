
#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    int base;
    cin >> base; // Indexing base: 0, 1, 2, 5, etc.

    // Adjacency List
    vector<vector<int>> adj(V + base);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    // Source node
    int start;
    cin >> start;

    vector<bool> visited(V + base, false);
    stack<int> st;

    cout << "DFS Traversal: ";

    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        cout << node << " ";

        // Check adjacent nodes in reverse order
        for (int i = (int)adj[node].size() - 1; i >= 0; i--) {
            int neighbor = adj[node][i];

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                st.push(neighbor);
            }
        }
    }

    cout << '\n';
    return 0;
}
