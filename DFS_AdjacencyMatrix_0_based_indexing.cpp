#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    int start;
    cin >> start;

    vector<bool> visited(n, false);
    stack<int> st; 

    cout << "DFS Traversal: ";

    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        cout << node << " ";

        
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                st.push(i);
            }
        }
    }
    
    cout << "\n";
    return 0;
}
