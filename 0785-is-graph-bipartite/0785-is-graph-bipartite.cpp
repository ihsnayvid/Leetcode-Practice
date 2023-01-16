class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &color, int col){
        color[node] = col;
        for(auto i: adj[node]){
            if(color[i] == col) return false;
            if(color[i] == -1){
                if(!dfs(i, adj, color, 1 - col)) return false;
            }
        }
        return true;
    }
	bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1);
	    for(int i=0; i<n; i++){
	        if(color[i] == -1) {
	            if(!dfs(i, adj, color, 0)) return false;
	        }
	    }
	    
	    return true;
    }
};