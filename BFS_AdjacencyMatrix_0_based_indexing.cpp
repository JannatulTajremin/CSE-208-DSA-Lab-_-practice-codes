// this code is for 0 based indexing 
//(means nodes value starts from 0,like nodes : 0,1,2,3)
//to make it 1 based indexing we have to do 
//vector<vector<int>>adj(n + 1,vector<int>(n + 1,0));
//vector<bool>visited (n + 1,false);
//for(int i = 1; i <= n; i++)

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int>(n,0)); // table create n*n
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v; // value input in the table
        
        // undirected (double direction) indicates
        adj[u][v]=1; // there is a connection from u to v
        adj[v][u]=1; // there is a connection from v to u
        // 1 means true
    }
    // source node
    int start;
    cin>>start;
    // false =unvisited 
    // initially all nodes will be unvisited
    // visited = { false ,false , false,false}
    vector<bool>visited (n,false);
    queue<int>q;
    // q = [0];
    visited[start] = true ;
    q.push(start);
    // visited = { true ,false , false,false}
    // q = [start]
    while (!q.empty()){
    int node = q.front();
    q.pop();
    // node = start
    // q =[0]
    cout<< node<<" ";
    //neighbour checking 
    //adj[node][i]==1 (i is the neighbour of node)
    //!visited[i] (i is never visited before)
    for(int i=0;i<n;i++){
        if(adj[node][i]==1 && !visited[i]){
            visited[i] = true ;
            q.push(i);
        }
    }
    
    }
    return 0;
}
