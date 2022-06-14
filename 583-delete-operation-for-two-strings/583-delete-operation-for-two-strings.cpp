class Solution {
public:
    
    int lcs(string x, string y, int m, int n){
        int dp[m+1][n+1];
        for(int i=0; i<m+1; i++) dp[i][0] = 0;
        for(int j=0; j<n+1; j++) dp[0][j] = 0;
        
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(x[i-1] == y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[m][n];       
    }
    
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        return (l1 + l2) - 2 * lcs(word1, word2, l1, l2);
    }
};