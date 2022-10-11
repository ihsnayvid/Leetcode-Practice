class Solution {
public:    
    vector<vector<int>> ans;
    
    void dfs(int i, int n, vector<int> &ds, vector<int> &vis, vector<vector<int>>& graph){
        ds.push_back(i);
        vis[i] = 1;
        if(i == n-1){
            ans.push_back(ds);
            ds.pop_back();
            vis[i] = 0;
            return;
        }
        for(auto x: graph[i]){
            if(!vis[x])
                dfs(x, n, ds, vis, graph);
        }
        vis[i] = 0;
        ds.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> ds;
        vis[0] = 1;
        dfs(0, n, ds, vis, graph);
        // for(auto i: graph[0]){
        //     ds.push_back(0);
        // }
        return ans;
    }
};