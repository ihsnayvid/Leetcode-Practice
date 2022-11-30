class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size(), mx = -1;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++) dp[i][m-1] = mat[i][m-1] - '0', mx = max(mx, dp[i][m-1]);
        for(int j=0; j<m; j++) dp[n-1][j] = mat[n-1][j] - '0', mx = max(mx, dp[n-1][j]);
        
        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){
                if(mat[i][j] == '1'){
                    dp[i][j] = min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1])) + 1;
                    mx = max(mx, dp[i][j]);
                }
            }
        }
        if(mx != -1)
            return mx * mx;
        return 0;
    }
};