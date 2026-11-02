// This code is for 0 based indexing
// Nodes = 0, 1, 2, 3...

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // Adjacency matrix create
    // Initially all values are 0
    vector<vector<int>>adj(n, vector<int>(n, 0));

    // Edge input (u, v, weight)
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // Undirected graph
        adj[u][v] = w;
        adj[v][u] = w;
    }

    // Initially all nodes are unvisited
    vector<bool>visited(n, false);

    // Starting node
    int start;
    cin >> start;

    // Minimum cost
    int total = 0;

    // MST needs n-1 edges
    int edgeCount = 0;

    // Start from the given node
    visited[start] = true;


    // Repeat until all nodes are connected
    while(edgeCount < n - 1)
    {
        int mn = INT_MAX;

        int x = -1;
        int y = -1;


        // Find minimum weight edge
        // whose one node is visited
        // and another node is unvisited

        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < n; j++)
                {
                    if(adj[i][j] != 0 && !visited[j])
                    {
                        if(adj[i][j] < mn)
                        {
                            mn = adj[i][j];

                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }


        // If no available edge exists
        // then graph is disconnected
        if(x == -1)
        {
            cout << "MST is not possible";
            return 0;
        }


        // Select the minimum edge
        cout << x << " - " << y << " : " << mn << endl;

        total += mn;

        // Mark new node as visited
        visited[y] = true;

        edgeCount++;
    }


    cout << "Minimum cost = " << total << endl;

    return 0;
}
