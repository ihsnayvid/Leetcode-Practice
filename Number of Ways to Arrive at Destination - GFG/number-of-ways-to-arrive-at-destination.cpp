//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
typedef pair<int, int> pi;
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<pair<int, int>> adj[n];
        
        for(auto i: roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        vector<int> dist(n, INT_MAX), ways(n, 0);
        dist[0] = 0, ways[0] = 1;
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()){
            auto d = pq.top().first, curr = pq.top().second;
            pq.pop();
            
            for(auto i: adj[curr]){
                auto node = i.first, wt = i.second;
                if(d + wt < dist[node]){
                    dist[node] = d + wt;
                    pq.push({dist[node], node});
                    ways[node] = ways[curr];
                }
                else if(d + wt == dist[node])
                    ways[node] = (ways[node] + ways[curr]) % mod;
            }
        }
        return ways[n-1] % mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends