class Solution {
public:
   
    int solve(int i, vector<int> &dp){
        if(i <= 1) return 1;
        if(dp[i]) return dp[i];
        for(int j=1; j<=i; j++)
            dp[i] += solve(j-1, dp) * solve(i-j, dp);
        return dp[i];
    }
    
    int numTrees(int n) {
        vector<int> dp(20);
        return solve(n, dp);        
    }
};