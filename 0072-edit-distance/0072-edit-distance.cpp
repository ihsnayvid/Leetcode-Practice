class Solution {
public:
    
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = solve(s1, s2, i-1, j-1, dp);
        else{
            int ins = 1 + solve(s1, s2, i, j-1, dp);
            int del = 1 + solve(s1, s2, i-1, j, dp);
            int rep = 1 + solve(s1, s2, i-1, j-1, dp);
            return dp[i][j] = min(ins, min(del, rep));
        }
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(word1, word2, n-1, m-1, dp);
    }
};