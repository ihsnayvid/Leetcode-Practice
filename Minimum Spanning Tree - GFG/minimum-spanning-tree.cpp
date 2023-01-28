//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> rank, size, parent;
    public:

    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++)
            parent[i] = i;
    }

    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pv == pu) return;

        if(rank[pu] < rank[pv])
            parent[pu] = pv;
        else if(rank[pv] < rank[pu])
            parent[pv] = pu;
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void UnionBySize(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pv == pu) return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        int sum = 0;
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0; i<n; i++){
            for(auto j: adj[i])
                edges.push_back({j[1], {i, j[0]}});
        }
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(n);
        
        for(auto i: edges){
            int wt = i.first;
            int u = i.second.first;
            int v = i.second.second;
                
            if(ds.findUPar(u) != ds.findUPar(v)){
                sum += wt;
                ds.UnionBySize(u, v);
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends