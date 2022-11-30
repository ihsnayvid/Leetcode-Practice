class Solution {
public:
    int get(int i, int j, int n, int m, vector<vector<int>> &mat){
        if(i < 0 or j < 0) return 0;
        if(i >= n) i = n-1;
        if(j >= m) j = m-1;
        return mat[i][j];
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=1; i<m; i++)
            mat[0][i] += mat[0][i-1];
        for(int i=1; i<n; i++)
            mat[i][0] += mat[i-1][0];
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++)
                mat[i][j] += (mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1]);
        }
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int total = get(i+k, j+k, n, m, mat);
                int sub1 = get(i+k, j-k-1, n, m , mat);
                int sub2 = get(i-k-1, j+k, n, m, mat);
                int add = get(i-k-1, j-k-1, n, m, mat);
                dp[i][j] = total - sub1 - sub2 + add;
            }
        }
        return dp;
    }
};