class Solution {
public:
    
    int lcs(string s1, string s2, int n, int m){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(s1[i] == s2[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else 
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }                
        }
        return dp[0][0];
    }
    
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        return (l1 + l2) - 2 * lcs(word1, word2, l1, l2);
    }
};