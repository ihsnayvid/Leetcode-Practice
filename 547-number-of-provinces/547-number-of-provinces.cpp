class Solution {
public:
    vector<int> visited;

    void dfs(int i, vector<vector<int>>& ic){
        if(visited[i]) return;
        visited[i] = 1;
        for(int j=0; j<ic.size(); j++){
            if(ic[i][j] == 1 and !visited[j])
                dfs(j, ic);
        }
    }
    int findCircleNum(vector<vector<int>>& ic) {
        int n = ic.size();
        visited.resize(n, 0);
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans++;
                dfs(i, ic);
            }
        }
        return ans;
    }
};