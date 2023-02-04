//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class DisjointSet{
    public:
    vector<int> rank, size, parent;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
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
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        //making components
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    for(int k=0; k<4; k++){
                        int nx = i + dx[k] , ny = j + dy[k];
                        if(nx < 0 or ny < 0 or nx >= n or ny >= n or !grid[nx][ny]) continue;
                        
                        int node = i * n + j;
                        int adjNode = nx * n + ny;
                        ds.UnionBySize(node, adjNode);
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> st;
                    for(int k=0; k<4; k++){
                        int nx = i + dx[k] , ny = j + dy[k];
                        if(nx < 0 or ny < 0 or nx >= n or ny >= n or !grid[nx][ny]) continue;
                        int adjNode = nx * n + ny;
                        st.insert(ds.findUPar(adjNode));
                    }
                    int count = 0;
                    for(auto x : st)
                        count += ds.size[x];
                    
                    ans = max(ans, count+1);
                }                
            }
        }

        for(int cell = 0; cell < n*n ; cell++)
            ans = max(ans, ds.size[ds.findUPar(cell)]);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends