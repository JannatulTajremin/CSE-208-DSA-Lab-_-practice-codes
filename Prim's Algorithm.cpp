#include <bits/stdc++.h>
using namespace std;

int main() {
    // ইনপুট-আউটপুট ফাস্ট করার অপ্টিমাইজেশন
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // কর্নার কেস: নোড ১টি হলে কোনো এজের প্রয়োজন নেই
    if (n == 1) {
        cout << "Edges in MST:\nTotal MST Cost = 0\n";
        return 0;
    }

    // অ্যাডজাসেন্সি লিস্ট (Adjacency List): ম্যাপ ব্যবহার করা হয়েছে যেকোনো নোড আইডি হ্যান্ডেল করতে
    // u -> {v, w}
    map<int, vector<pair<int, int>>> adj;
    set<int> unique_nodes; // গ্রাফের নোডগুলো ট্র্যাক করতে

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // আনডাইরেক্টেড গ্রাফ (Undirected Graph)
        unique_nodes.insert(u);
        unique_nodes.insert(v);
    }

    // কোনো নোড MST তে ভিজিট হয়েছে কিনা তা ট্র্যাক করার জন্য ম্যাপ
    map<int, bool> inMST;
    for (int node : unique_nodes) {
        inMST[node] = false;
    }

    // Priority Queue (Min-Heap) তৈরি: এটি সবসময় সর্বনিম্ন ওজনের এজটিকে উপরে রাখবে
    // ফর্ম্যাট: {weight, {current_node, parent_node}}
    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> pq;

    // গ্রাফের যেকোনো একটি নোড থেকে শুরু করি (ধরা যাক unique_nodes এর প্রথম নোডটি)
    int start_node = *unique_nodes.begin();
    
    // প্রারম্ভিক অবস্থা: ওজন ০, নোড = start_node, প্যারেন্ট = -1 (কোনো প্যারেন্ট নেই)
    pq.push({0, {start_node, -1}});

    long long totalCost = 0;
    int edgeCount = 0;

    cout << "Edges in MST:\n";

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int w = top.first;
        int u = top.second.first;
        int parent = top.second.second;

        // নোডটি যদি ইতিমধ্যেই MST তে যুক্ত হয়ে থাকে, তবে এটি স্কিপ করব (সাইকেল এড়াতে)
        if (inMST[u]) continue;

        // নোডটিকে MST তে অন্তর্ভুক্ত করি
        inMST[u] = true;
        
        // যদি এটি শুরুর নোড না হয়, তবে MST এর এজ হিসেবে প্রিন্ট করব
        if (parent != -1) {
            cout << parent << " - " << u << " : " << w << "\n";
            totalCost += w;
            edgeCount++;
        }

        // নোড 'u' এর সাথে সংযুক্ত সব প্রতিবেশীদের (Neighbors) চেক করি
        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // প্রতিবেশী নোডটি যদি এখনও MST তে যুক্ত না হয়ে থাকে
            if (!inMST[v]) {
                pq.push({weight, {v, u}});
            }
        }
    }

    // Spanning Tree তে নোড সংখ্যা n হলে এজ সংখ্যা ঠিক (n-1) হতে হবে
    if (edgeCount == n - 1) {
        cout << "Total MST Cost = " << totalCost << "\n";
    } else {
        cout << "MST is not possible. Graph is disconnected.\n";
    }

    return 0;
}
