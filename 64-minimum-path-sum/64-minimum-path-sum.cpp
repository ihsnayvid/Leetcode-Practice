class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = grid[m-1][n-1];
        
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i == m-1 and j == n-1) continue;
                
                int cell1 = (i+1<m) ? dp[i+1][j] : INT_MAX;
                int cell2 = (j+1<n) ? dp[i][j+1] : INT_MAX;
                dp[i][j] = grid[i][j] + min(cell1, cell2);
            }
        }
        return dp[0][0];
    }
};