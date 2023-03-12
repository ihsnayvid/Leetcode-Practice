//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
    public:
    vector<int> rank, size, parent;

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

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int row = 0, col = 0;
        for(auto i: stones){
            row = max(row, i[0]);
            col = max(col, i[1]);
        }
        DisjointSet ds(row + col + 1);
        
        unordered_set<int> st;
        for(auto i: stones){
            int r = i[0];
            int c = i[1] + row + 1;
            ds.UnionBySize(r, c);
            st.insert(r);
            st.insert(c);
        }
        int count = 0;
        for(auto i: st){
            if(ds.findUPar(i) == i) count++;
        }
        return n - count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends