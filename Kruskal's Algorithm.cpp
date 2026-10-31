#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

// এজ-এর ওজন অনুযায়ী ছোট থেকে বড় সাজানোর জন্য কম্প্যারেটর
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    // ইনপুট-আউটপুট ফাস্ট করার জন্য অপ্টিমাইজেশন
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //n=nodes , m=edges
    int n, m;
    cin >> n >> m;

    // Corner Case: if node(n)=1 ,edge will be 0
    if (n == 1) {
        cout << "Edges in MST:\nTotal MST Cost = 0\n";
        return 0;
    }

    vector<Edge> edges(m);
    set<int> unique_nodes; 

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        unique_nodes.insert(edges[i].u);
        unique_nodes.insert(edges[i].v);
    }

    // ওজনের ক্রমানুসারে এজগুলো সর্ট করা
    sort(edges.begin(), edges.end(), cmp);

    // যেকোনো এলোমেলো বা বড় আইডি হ্যান্ডেল করার জন্য ম্যাপ
    map<int, int> parent;
    
    // শুধু ইনপুটে থাকা নোডগুলোর প্যারেন্ট ইনিশিয়ালাইজ করা
    for (int node : unique_nodes) {
        parent[node] = node;
    }

    long long totalCost = 0;
    int edgeCount = 0;

    cout << "Edges in MST:\n";

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        // --- Find Parent (Map ভিত্তিক Path Compression) ---
        int root_u = u;
        while (root_u != parent[root_u]) {
            root_u = parent[root_u];
        }
        int curr_u = u;
        while (curr_u != root_u) {
            int nxt = parent[curr_u];
            parent[curr_u] = root_u;
            curr_u = nxt;
        }

        int root_v = v;
        while (root_v != parent[root_v]) {
            root_v = parent[root_v];
        }
        int curr_v = v;
        while (curr_v != root_v) {
            int nxt = parent[curr_v];
            parent[curr_v] = root_v;
            curr_v = nxt;
        }
        // ------------------------------------------------

        // সাইকেল তৈরি না করলে MST তে যোগ করা হবে
        if (root_u != root_v) {
            cout << u << " - " << v << " : " << w << "\n";

            totalCost += w;
            edgeCount++;

            parent[root_u] = root_v; // Union Operation

            if (edgeCount == n - 1)
                break;
        }
    }

    if (edgeCount == n - 1) {
        cout << "Total MST Cost = " << totalCost << "\n";
    } else {
        cout << "MST is not possible. Graph is disconnected.\n";
    }

    return 0;
}
