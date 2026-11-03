#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main(){
    int n, m;
    cin >> n >> m;
    
    // হুবহু BFS-এর মতো n*n এর Adjacency Matrix (টেবিল) তৈরি
    // কানেকশন না থাকলে ০-এর বদলে INF দিয়ে ফিল করা হয়েছে
    vector<vector<ll>> adj(n, vector<ll>(n, INF)); 
    
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w; // নোডের সাথে weight (w) ইনপুট
        
        adj[u][v] = w; // u থেকে v এর কানেকশন খরচ 
        adj[v][u] = w; // v থেকে u এর কানেকশন খরচ (Undirected graph)
    }

    // source node বা শুরুর নোড
    int start;
    cin >> start;

    // BFS-এ ছিল: vector<bool> visited (n, false);
    // Dijkstra-তে: Distance array (শুরুতে সব INF)
    vector<ll> dist(n, INF);

    // BFS-এ ছিল: queue<int> q;
    // Dijkstra-তে: Min-Heap priority queue {distance, node}
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

    // BFS-এ ছিল: visited[start] = true; q.push(start);
    // Dijkstra-তে: শুরুর নোডের দূরত্ব ০ এবং সেটা কিউতে পুশ
    dist[start] = 0;
    q.push({0, start});

    while (!q.empty()){
        // BFS-এর মতোই ফ্রন্ট এলিমেন্ট বের করা
        ll d = q.top().first;
        int node = q.top().second;
        q.pop();

        // অপ্রয়োজনীয় বা পুরোনো ভ্যালু স্কিপ করা
        if (d > dist[node]) continue;

        // Neighbour checking (হুবহু তোমার BFS কোডের মতো ০ থেকে n পর্যন্ত লুপ)
        for(int i = 0; i < n; i++){
            
            // BFS-এ কন্ডিশন ছিল: if(adj[node][i]==1 && !visited[i])
            // Dijkstra-তে কন্ডিশন: কানেকশন আছে কিনা এবং দূরত্ব কমানো সম্ভব কিনা
            if(adj[node][i] != INF && dist[node] + adj[node][i] < dist[i]){
                
                // BFS-এ ছিল: visited[i] = true;
                // Dijkstra-তে: দূরত্ব আপডেট করা
                dist[i] = dist[node] + adj[node][i];
                
                // BFS-এ ছিল: q.push(i);
                // Dijkstra-তে: নতুন দূরত্বসহ কিউতে পুশ
                q.push({dist[i], i});
            }
        }
    }

    // আউটপুট প্রিন্ট (০ থেকে n-1 পর্যন্ত)
    cout << "Shortest distances from start node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " : ";
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}
