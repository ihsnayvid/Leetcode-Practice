class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(dp[n] != -1) return dp[n];
        if(n == 2) return dp[n] = 1;
        if(n == 3) return dp[n] = 2;
        if(n == 4) return dp[n] = 4;
        if(n == 5) return dp[n] = 6;
        if(n == 6) return dp[n] = 9;
        return dp[n] = 3 * solve(n-3, dp);
    }
    int integerBreak(int n) {        
        vector<int> dp(n+2, -1);
        return solve(n, dp);
    }
};