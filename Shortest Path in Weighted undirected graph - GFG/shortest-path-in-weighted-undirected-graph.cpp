//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> parent(n+1, 0);
        vector<long> dist(n+1, INT_MAX);
        vector<pair<int, int>> adj[n+1];
        
        for(auto i: edges){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        dist[1] = 0;
        pq.push({0, 1});
        parent[1] = 1;
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto i: adj[node]){
                int newdist = d + i.second;
                int v = i.first;
                if(newdist < dist[v]){
                    dist[v] = newdist;
                    parent[v] = node;
                    pq.push({newdist, v});
                }
            }
        }
        
        if(dist[n] == INT_MAX) return {-1};
        vector<int> ans;
        int dst = n;
        while(parent[dst] != dst){
            ans.push_back(dst);
            dst = parent[dst];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends