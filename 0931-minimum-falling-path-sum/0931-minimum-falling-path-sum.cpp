class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size(), ans = INT_MAX; 
        if(n == 1) return mat[0][0];
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int left = j-1 >= 0 ? mat[i+1][j-1] : INT_MAX;
                int right = j+1 < n ? mat[i+1][j+1] : INT_MAX;
                int down = mat[i+1][j];
                mat[i][j] += min(left, min(right, down));
                if(i == 0)
                    ans = min(ans, mat[i][j]);
            }
        }
        return ans;
    }
};