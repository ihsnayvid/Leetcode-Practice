//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<pair<int, int>> adj[n];
        vector<int> dist(n, INT_MAX);
        
        for(auto i: flights)
            adj[i[0]].push_back({i[1], i[2]});
        
        queue<pair<int, pair<int, int>>> q;
        //stops, node, cost/dist
        
        q.push({0,{src, 0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if(stops > k) continue;
            for(auto i: adj[node]){
                int curr = i.first;
                int wt = i.second;
                if(cost + wt < dist[curr] and stops <= k){
                    dist[curr] = cost + wt;
                    q.push({stops+1, {curr, dist[curr]}});
                }
            }
        }
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends