```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int base;
    cin >> base; // Starting index: 0, 1, 2, etc.

    // Adjacency Matrix
    vector<vector<int>> adj(n + base, vector<int>(n + base, 0));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    // Source node
    int start;
    cin >> start;

    vector<bool> visited(n + base, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        // Check all possible neighbours
        for (int i = base; i < n + base; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << '\n';
    return 0;
}
```
