class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    void dfs(vector<vector<char>> &grid, int x, int y, int n, int m){
        if(x < 0 or y < 0 or x > n or y > m or grid[x][y] == '0') return;
        grid[x][y] = '0';
        for(int i=0; i<4; i++)
            dfs(grid, x + dx[i], y + dy[i], n, m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans ++;
                    dfs(grid, i, j, n-1, m-1);
                }
            }
        }
        return ans;
    }
};