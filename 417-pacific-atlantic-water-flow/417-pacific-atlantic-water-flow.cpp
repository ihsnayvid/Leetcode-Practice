class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    
    void dfs(vector<vector<int>> &heights, vector<vector<int>> &visited, int x, int y){
        int n = heights.size(), m = heights[0].size();
        
        visited[x][y] = 1;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 and ny >= 0 and nx < n and ny < m and !visited[nx][ny] and heights[nx][ny] >= heights[x][y])
                dfs(heights, visited, nx, ny);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        
        vector<vector<int>> pacific(n, vector<int> (m, 0));
        vector<vector<int>> atlantic(n, vector<int> (m, 0));
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++){
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m-1);
        }
        
        for(int i=0; i<m; i++){
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, n-1, i);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j] and atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};