//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int n, vector<int> graph[], vector<int> &vis){
        vis[n] = 1;
        for(auto i: graph[n]){
            if(!vis[i]){
                dfs(i, graph, vis);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int n) {
        int ans = 0;
        vector<int> vis(n, 0);
        vector<int> graph[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(adj[i][j] == 1)
                    graph[i].push_back(j);
            }
        }
        
        // cout<<"graph is \n";
        // for(auto i: graph){
        //     for(auto j: i) cout<<j<<".";
        //     cout<<"\n";
        // }
        
        
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                dfs(i, graph, vis);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends