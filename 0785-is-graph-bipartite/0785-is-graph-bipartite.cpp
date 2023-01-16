class Solution {
public:
    bool bfs(int node, vector<vector<int>> &adj, vector<int> &color){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            int col = color[curr];
            for(auto i: adj[curr]){
                if(color[i] == col) return false;
                if(color[i] == -1){
                    color[i] = 1 - col;
                    q.push(i);
                }
            }
        }
        return true;
    }

	bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
	    for(int i=0; i<n; i++){
	        if(color[i] == -1) {
	            color[i] = 0;
	            if(!bfs(i, graph, color)) return false;
	        }
	    }
	    
	    return true;
    }
};