#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    int base;
    cin >> base; // Starting index: 0, 1, 2, etc.

    // Adjacency List: {neighbor, weight}
    vector<vector<pair<int, int>>> adj(n + base);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }

    int source;
    cin >> source;
    
    //           0   1   2   3   4   5
    // dist = { INF,INF,INF,INF,INF,INF}
    // n+base = 5+1 = 6
    vector<ll> dist(n + base, INF);

    // Min-Heap: {distance, node}
    // ll= distance from source 
    // int = node number 
    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;


    //dist = { INF,0,INF,INF,INF,INF }
    //pq = {0,1}
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        //  pq={0,1} ;d = 0
        // node = 1
        ll d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Ignore outdated entries
        if (d != dist[node])
            continue;

        for (auto edge : adj[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    cout << "Shortest distances from source " << source << ":\n";

    for (int i = base; i < n + base; i++) {
        cout << "Node " << i << " : ";

        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }

    return 0;
}
