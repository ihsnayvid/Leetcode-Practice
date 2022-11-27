class Solution {
public:
   
    // int solve(int i, vector<int> &dp){
    //     if(i <= 1) return 1;
    //     if(dp[i]) return dp[i];
    //     for(int j=1; j<=i; j++)
    //         dp[i] += solve(j-1, dp) * solve(i-j, dp);
    //     return dp[i];
    // }
    
    int numTrees(int n) {
        vector<int> dp(20);
        if(n <= 1) return 1;
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++)
                dp[i] += dp[j-1] * dp[i-j];
        }
        return dp[n];        
    }
};