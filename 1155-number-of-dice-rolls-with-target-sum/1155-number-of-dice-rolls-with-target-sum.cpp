class Solution {
public:
    vector<vector<int>> dp;
    const int mod = 1000000007;
    int solve(int n, int k, int target){
        if(n == 0 and target == 0) return 1;
        if(n <= 0 or target <= 0) return 0;
        if(dp[n][target] != -1) return dp[n][target];
        
        int ans = 0;
        for(int i=1; i<=k; i++)
            ans = ((ans % mod) + (solve(n-1, k, target - i) % mod)) % mod;
        
        return dp[n][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(31, vector<int>(1001, -1));
        return solve(n, k, target);
    }
};