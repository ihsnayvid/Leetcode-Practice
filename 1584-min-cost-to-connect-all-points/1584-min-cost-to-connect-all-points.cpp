class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size();
        
        vector<vector<int>> adj[n];
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int wt = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }
        
        //prim's
        int sum = 0;
        vector<int> vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if(vis[u]) continue;
            vis[u] = 1;
            sum += d;
            for(auto &i: adj[u]){
                int v = i[0], wt = i[1];
                if(!vis[v]) pq.push({wt, v});
            }
        }
        return sum;
    }
};