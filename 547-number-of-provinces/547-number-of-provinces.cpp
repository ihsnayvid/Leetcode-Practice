class Solution {
public:
    vector<int> visited;

    void dfs(int i, vector<int> adj[]){
        if(visited[i]) return;
        visited[i] = 1;
        for(auto x: adj[i]){
            if(!visited[x])
                dfs(x, adj);
        }
    }
    int findCircleNum(vector<vector<int>>& ic) {
        int n = ic.size();
        visited.resize(n, 0);
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
            if(ic[i][j] == 1)
                adj[i].push_back(j);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans++;
                dfs(i, adj);
            }
        }
        return ans;
    }
};