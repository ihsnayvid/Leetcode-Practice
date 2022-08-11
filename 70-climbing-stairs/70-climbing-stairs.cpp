class Solution {
public:
//     int solve(int idx, vector<int> &dp){
//         if(idx == 0) return 1;
//         if(idx < 0) return 0;
        
//         if(dp[idx] != -1) return dp[idx];
        
//         return dp[idx] = solve(idx-1, dp) + solve(idx-2, dp);
//     }
    
    int climbStairs(int n) {
        // vector<int> dp(46,-1);
        // solve(n, dp);
        
        vector<int> dp(n+1,0);
        if(n == 1) return 1;
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
};