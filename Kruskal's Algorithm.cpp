// This code is for 0 based indexing
// Nodes = 0, 1, 2, 3...

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // Edge store করার জন্য 3টি vector
    vector<int>u(m), v(m), w(m);

    // Parent array
    int parent[100];

    int total = 0;


    // Initially every node is its own parent
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }


    // Edge input
    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }


    // Sort edges by weight (ascending order)
    for(int i = 0; i < m - 1; i++)
    {
        for(int j = i + 1; j < m; j++)
        {
            if(w[i] > w[j])
            {
                swap(w[i], w[j]);
                swap(u[i], u[j]);
                swap(v[i], v[j]);
            }
        }
    }


    cout << "Selected edges:\n";


    // Check every sorted edge
    for(int i = 0; i < m; i++)
    {
        int a = u[i];
        int b = v[i];


        // Find parent of u[i]
        while(parent[a] != a)
        {
            a = parent[a];
        }


        // Find parent of v[i]
        while(parent[b] != b)
        {
            b = parent[b];
        }


        // If parents are different, no cycle will form
        if(a != b)
        {
            cout << u[i] << " - " << v[i]
                 << " : " << w[i] << endl;

            total += w[i];


            // Union operation
            parent[a] = b;
        }
    }


    cout << "Minimum cost = " << total << endl;

    return 0;
}
