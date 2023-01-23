//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ppi pair<int, pair<int, int>> 
class Solution {
  public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    int MinimumEffort(vector<vector<int>>& h) {
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        int n = h.size(), m = h[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int r = p.second.first;
            int c = p.second.second;
            
            if(r == n-1 and c == m-1) return d;
            
            for(int i=0; i<4; i++){
                int nr = r + dx[i], nc = c + dy[i];
                if(nr < 0 or nc < 0 or nr >= n or nc >= m) continue;
                int diff = abs(h[r][c] - h[nr][nc]);
                int neweff = max(diff, d);
                if(neweff < dist[nr][nc]){
                    dist[nr][nc] = neweff;
                    pq.push({neweff, {nr, nc}});
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends