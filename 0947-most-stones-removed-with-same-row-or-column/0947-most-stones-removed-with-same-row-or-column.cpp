class Solution {
public:
    int dfs(int idx, int n, vector<vector<int>> &stones, vector<bool> &vis){
        vis[idx] = 1;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i] and (stones[i][0] == stones[idx][0] or stones[i][1] == stones[idx][1]))
                ans += (dfs(i, n, stones, vis) + 1);
        }
        return ans;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i])
                ans += dfs(i, n, stones, vis);
        }
        return ans;
    }
};