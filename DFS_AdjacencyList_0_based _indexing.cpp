// this is a 0 based indexing code 
//to make it i based indexing code we have to do 
//vector<vector<int>> adj(V + 1);
//vector<bool> visited(V + 1, false);
// n_based indexing 
//vector<vector<int>> adj(V + n);
//vector<bool> visited(V + n, false);
#include <bits/stdc++.h>
using namespace std;

int main() {

    int V, E;
    cin >> V >> E;

    // Adjacency List
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }
    // source node 
    int start;
    cin >> start;

    
    vector<bool> visited(V, false);
    stack<int> st;

    cout << "DFS Traversal: ";

    //source node push in the stack
    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        cout << node << " ";

        // Adjacent nodes checking 
        // The loop is run in reverse to match the exact traversal order of recursive DFS
        for (int i = adj[node].size() - 1; i >= 0; i--) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Marking as visited at the time of pushing to stack
                st.push(neighbor);
            }
        }
    }
    
    cout << "\n";
    return 0;
}
