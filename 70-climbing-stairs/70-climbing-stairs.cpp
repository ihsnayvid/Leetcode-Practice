class Solution {
public:
    int solve(int idx, vector<int> &dp){
        if(idx == 0) return 1;
        if(idx < 0) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        return dp[idx] = solve(idx-1, dp) + solve(idx-2, dp);
    }
    
    int climbStairs(int n) {
        vector<int> dp(46,-1);
        solve(n, dp);
        return dp[n];
    }
};